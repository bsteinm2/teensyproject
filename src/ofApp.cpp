#include "ofApp.h"
#include <array>

using std::array;
using std::cout;

void ofApp::setup()
{
    ofSetVerticalSync(true);
    // setup device port for the Arduino. Set at firmata bitrate
    serial.setup("/dev/ttyACM0", 9600);
    serial.startContinuousRead();
    ofAddListener(serial.NEW_MESSAGE, this, &ofApp::onNewMessage);
    ardSetup_ = true;
    soundSetup_ = false;

    message = "";
}

void ofApp::update()
{
    //updates sound engine
    if (ardSetup_ && !soundSetup_)
    {
        soundPlayer.load("rollthebones.mp3");
        soundPlayer.play();
        soundSetup_ = true;
        isPlaying_ = true;
    }
    if (isPlaying_ && message != "" && ardSetup_ == true) {
        cout << "sending message: " << message << "\n";
        serial.writeString(message);
        message = "";
        ofSoundUpdate();
    }
}

void ofApp::draw()
{

    //bins 0 through 40 contain the easiest frequencies to discern
    float *fftArr = ofSoundGetSpectrum(numSamples);
    array<float, 512> data;
    // const int *end = fftArr + numSamples;
    array<3> lastMsgTotals;

    for (size_t i = 0; i < data.size(); ++i)
    {
        data[i] = fftArr[i];
    }

    if (!ardSetup_)
    {
        ofDrawBitmapString("arduino not ready...\n", 515, 40);
    }

    int width = ofGetWindowWidth() / 5;
    int height = ofGetWindowHeight() / 40;

    int numDrawn = 0;
    for (size_t j = 0; j < 40; ++j)
    {
        pair<int, int> position = barPosition(numDrawn, height);

        if (data[j] > ksmooth)
        {

            ofSetColor(barColor(j, data[j]));
            ofDrawRectangle(position.first, position.second, width, height);
            ++numDrawn;

            if (j < 10) {
                message += "a";
            } else if (j < 25) {
                message += "b";
            } else {
                message += "c";
            }
        } 
    }
    message += '|';
}

void ofApp::onNewMessage(string &message)
{
	cout << "onNewMessage, message: " << message << "\n";
	
    // switch (message) {
    //     case "r":
    //         Pixel.r = 
    // }
	// Pixel.r = (message == "r");
	// Pixel.g = (message == "g");
	// Pixel.b = (message == "b");
}


void ofApp::keyPressed(int key)
{
    if (isPlaying_)
    {
        if (key == OF_KEY_SPACE)
        {
            soundPlayer.setPaused(true);
            isPlaying_ = false;
        }
    }
    else if (isPlaying_ == false)
    {
        if (key == OF_KEY_SPACE)
        {
            soundPlayer.setPaused(false);
            isPlaying_ = true;
        }
    }
}

/** we want to sample a few frequency bins, so divide numSamples to something that fills the screen nice.
* Then, divide 'num' by numSamples and the truncated answer gives the box number
* based on that, give logic for its position based on the screen size
*/
pair<int, int> ofApp::barPosition(size_t num, int height)
{
    pair<int, int> position;
    position.first = 0;
    position.second = height * num;
    return position;
}

/**
 * Assign colors based on the bin number. The higher the bin, the higher the frequency.
 */
ofColor ofApp::barColor(int num, float val)
{
    if (val > ksmooth)
    {
        if (num < 10)
        {
            ofColor red(255, 0, 0);
            return red;
        }
        else if (num < 25)
        {
            ofColor yellow(255, 255, 0);
            return yellow;
        }
        else
        {
            ofColor green(0, 255, 0);
            return green;
        }
    }
    else
    {
        ofColor white(0, 0, 0);
        return white;
    }
}


