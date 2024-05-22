#pragma once
#include "ofMain.h"
#include "ofxSimpleSerial.h"

#include <vector>
#include <string>
#include <utility>

using std::pair;
using std::vector;
using std::string;

class ofApp : public ofBaseApp
{
private:
  ofSoundPlayer soundPlayer;
  ofxSimpleSerial serial;

  bool isPlaying_ = false;
  bool soundSetup_;
  bool ardSetup_;

  const int OF_KEY_SPACE = 32;
  static const int numSamples = 512;
  const float ksmooth = .015; // .025

public:
  typedef struct Pixel {
    bool r;
    bool g;
    bool b;
  };

  string message;

  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  pair<int, int> barPosition(size_t num, int height);
  ofColor barColor(int num, float val);

  void onNewMessage(string &message);
};
