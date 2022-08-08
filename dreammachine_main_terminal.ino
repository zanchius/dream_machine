#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN       5 // On Trinket or Gemma, suggest changing this to 1

#define NUMPIXELS 8 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
//#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
//  clock_prescale_set(clock_div_1);
//#endif

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);
}

void loop(){

  Serial.println("Enter RGB delay:");
  while (Serial.available() == 0 ){}
  int a = Serial.parseInt();
  Serial.println(a);

  Serial.flush();

  Serial.println("Enter loop duration:");
  while (Serial.available() == 0){}
  int l = Serial.parseInt();
  Serial.println(l);

  for (int i; i < l; i++){
      cycleLEDs(a);
      }
  Serial.flush();
}  

void cycleLEDs(int d){  
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  pixels.setPixelColor(7, pixels.Color(0, 255, 0));
  pixels.show();
  delay(d);

 pixels.clear(); // Set all pixel colors to 'off'
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.setPixelColor(7, pixels.Color(255, 0, 0));
  pixels.show();
  delay(d);

 pixels.clear(); // Set all pixel colors to 'off'
  pixels.setPixelColor(0, pixels.Color(0, 0, 255));
  pixels.setPixelColor(7, pixels.Color(0, 0, 255));
  pixels.show();
  delay(d);
}
