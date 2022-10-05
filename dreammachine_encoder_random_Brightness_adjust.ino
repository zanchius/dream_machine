#include "EncoderTool.h"
using namespace EncoderTool;
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define PIN       30 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 2 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

pinMode(A8, INPUT_PULLUP);
pinMode(A9, INPUT_PULLUP);

pinMode(A10, INPUT_PULLUP);
pinMode(A11, INPUT_PULLUP);

pinMode(A12, INPUT_PULLUP);
pinMode(A13, INPUT_PULLUP);

pinMode(A14, INPUT_PULLUP);
pinMode(A15, INPUT_PULLUP);

constexpr uint8_t pinA = A8, pinB = A9, pinBtnA = 10;
constexpr uint8_t pinC = A10, pinD = A11, pinBtnB = 11;
constexpr uint8_t pinE = A12, pinF = A13, pinBtnC = 12;
constexpr uint8_t pinG = A14, pinH = A15, pinBtnD = 14;

Encoder enc1;
Encoder enc2;
Encoder enc3;
Encoder enc4;

int i;
int l;
long ar;
long ag;
long ab;
bool button4;
bool button4_state;

void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();

  enc1.begin(pinA, pinB, pinBtnA);
  enc2.begin(pinC, pinD, pinBtnB);
  enc3.begin(pinE, pinF, pinBtnC);
  enc4.begin(pinG, pinH, pinBtnD);

  enc1.setLimits(0,255);
  enc2.setLimits(0,255);
  enc3.setLimits(0,255);
  enc4.setLimits(0,255);

  enc1.setValue(0);
  enc2.setValue(0);
  enc3.setValue(0);
  enc4.setValue(1);

  button4_state = enc4.getButton();
  
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font
  display.display();

}

int checkknobs(){
//  enc1.tick();
//  enc2.tick();
//  enc3.tick();
  enc4.tick();

  if (enc4.valueChanged())
  {
//    ar = enc1.getValue();
//    ag = enc2.getValue();
//    ab = enc3.getValue();
    int bright = enc4.getValue();
    return bright;
  }

  
}
void loop(){
    l = checkknobs();
    randomSeed(analogRead(A0));
    ar = random(3,50);
    //randomSeed(analogRead(A0));
    ag = random(3,50);
    //randomSeed(analogRead(A0));
    ab = random(3,50);

    display.setCursor(0,0);
    display.print("Red ms: ");
    display.setCursor(43,0);
    display.print(ar);
    display.setCursor(0, 12);
    display.print("Green ms: ");
    display.setCursor(55, 12);
    display.print(ag);
    display.setCursor(0, 24);
    display.print("Blue ms: ");
    display.setCursor(50, 24);
    display.print(ab);
    display.drawLine(68, 0, 68,32, SSD1306_WHITE);
    display.setCursor(74, 0);
    display.print("Lum: ");
    display.setCursor(100, 0);
    display.print(l);
    display.display();
    display.clearDisplay();

    if(l>10 || l<255){
   for(i=0;i<500;i++){

          pixels.setBrightness(l);
    
          pixels.clear(); // Set all pixel colors to 'off'
          pixels.setPixelColor(0, pixels.Color(0, 255, 0));
          pixels.setPixelColor(1, pixels.Color(0, 255, 0));
          pixels.show();
          delay(ar);

          pixels.clear(); // Set all pixel colors to 'off'
          pixels.setPixelColor(0, pixels.Color(255, 0, 0));
          pixels.setPixelColor(1, pixels.Color(255, 0, 0));
          pixels.show();
          delay(ag);

          pixels.clear(); // Set all pixel colors to 'off'
          pixels.setPixelColor(0, pixels.Color(0, 0, 255));
          pixels.setPixelColor(1, pixels.Color(0, 0, 255));
          pixels.show();
          delay(ab);

          }
    }
              else{
            l=10;
            }

}
