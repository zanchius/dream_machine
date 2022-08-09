#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN       5 // On Trinket or Gemma, suggest changing this to 1

#define NUMPIXELS 2 // Popular NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
//#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
//  clock_prescale_set(clock_div_1);
//#endif

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

int i;

void loop(){
  Serial1.begin(9600);

  Serial1.println("Enter RGB delay:");
  while (Serial1.available() == 0 ){}
  int a = Serial1.parseInt(SKIP_ALL);
  Serial1.println(a);

  Serial1.println("Enter loop duration:");
  while (Serial1.available() == 0 ){}
  int l = Serial1.parseInt(SKIP_ALL);
  Serial1.println(l);

  for (i; i < l; i++){
    pixels.clear(); // Set all pixel colors to 'off'
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));
    pixels.setPixelColor(1, pixels.Color(0, 255, 0));
    pixels.show();
    delay(a);

    pixels.clear(); // Set all pixel colors to 'off'
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));
    pixels.show();
    delay(a);

    pixels.clear(); // Set all pixel colors to 'off'
    pixels.setPixelColor(0, pixels.Color(0, 0, 255));
    pixels.setPixelColor(1, pixels.Color(0, 0, 255));
    pixels.show();
    delay(a);
    }
    i=0;
    Serial1.end();
}
