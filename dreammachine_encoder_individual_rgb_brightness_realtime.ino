#include <Encoder.h>
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define PIN       30 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 2 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Encoder enc1(A9,A8);
Encoder enc2(A10,A11);
Encoder enc3(A12,A13);
Encoder enc4(A14,A15);

int i;
long l;
long ar;
long ag;
long ab;

void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.clearDisplay();

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font
  display.display();

}

void checkknobs(){

    if(enc1.read() < 0){
      ar = 0;
    }
    else{
      ar = enc1.read();
    }

    if(enc2.read() < 0){
      ag = 0;
    }
    else{
      ag = enc2.read();
    }
    
    if(enc3.read() < 0){
      ab = 0;
    }
    else{
      ab = enc3.read();
    }

    if(enc4.read() < 0){
      l = 0;
    }
    else{
      l = enc4.read();
    }

}

void disp(){
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
}

void loop(){

          checkknobs();

          disp();

          pixels.clear(); // Set all pixel colors to 'off'
          pixels.setPixelColor(0, pixels.Color(l, 0, 0));
          pixels.setPixelColor(1, pixels.Color(l, 0, 0));
          pixels.show();
          delay(ar);

          pixels.clear(); // Set all pixel colors to 'off'
          pixels.setPixelColor(0, pixels.Color(0, l, 0));
          pixels.setPixelColor(1, pixels.Color(0, l, 0));
          pixels.show();
          delay(ag);

          pixels.clear(); // Set all pixel colors to 'off'
          pixels.setPixelColor(0, pixels.Color(0, 0, l));
          pixels.setPixelColor(1, pixels.Color(0, 0, l));
          pixels.show();
          delay(ab);
}
