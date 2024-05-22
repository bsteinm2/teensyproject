#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(144, PIN, NEO_GRB + NEO_KHZ800);

char message[] = "";

char messageBuffer[] = "";

int numBufferedChars = 0;

int numMessageChars = 0;


void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(32);
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
   for (int i = 0; i < strip.numPixels(); i++) {
     strip.setPixelColor(i, strip.Color(0, 0, 0));
   }
  
   if (Serial.available() > 0) {
     char readBytes[40] = {'\0'};
     Serial.readBytes(readBytes, 40);
     useMessage(readBytes, 40);
     
   }
}


void useMessage(char* message, int length)
{
  int numDrawn = 0;
  for(int i = 0;i<length;i++)
  {
    switch (message[i]) {
     case 'a':
      {
        strip.setPixelColor(numDrawn, strip.Color(150, 0, 0));
        numDrawn++;
        strip.setPixelColor(numDrawn, strip.Color(150, 0, 0));
        numDrawn++;
        strip.setPixelColor(numDrawn, strip.Color(150, 0, 0));
        numDrawn++;
        strip.setPixelColor(numDrawn, strip.Color(150, 0, 0));
        numDrawn++;
        //delay(10);
        break;
      }
     case 'b':
      {
        strip.setPixelColor(numDrawn, strip.Color(150, 150, 0));
        numDrawn++;
        strip.setPixelColor(numDrawn, strip.Color(150, 150, 0));
        numDrawn++;
        strip.setPixelColor(numDrawn, strip.Color(150, 150, 0));
        numDrawn++;
        strip.setPixelColor(numDrawn, strip.Color(150, 150, 0));
        numDrawn++;
        //delay(10);
        break;  
      }
     case 'c':
      {
        strip.setPixelColor(numDrawn, strip.Color(0, 150, 0));
        numDrawn++;
        strip.setPixelColor(numDrawn, strip.Color(0, 150, 0));
        numDrawn++;
        strip.setPixelColor(numDrawn, strip.Color(0, 150, 0));
        numDrawn++;
        strip.setPixelColor(numDrawn, strip.Color(0, 150, 0));
        numDrawn++;
        //delay(10);
        break;
      }
     case '|':
     {
      i = length;
      break; 
     }
     default:
      break; 
    }
  }
  strip.show();
  delay(10);
}
