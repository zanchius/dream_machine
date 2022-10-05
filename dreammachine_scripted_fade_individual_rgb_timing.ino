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

int i = 0;
int b = 0;

void loop(){
  Serial.begin(9600);

  Serial.println("Enter Red delay:");
  while (Serial.available() == 0 ){}
  int ar = Serial.parseInt(SKIP_ALL);
  Serial.println(ar);

  Serial.println("Enter Green delay:");
  while (Serial.available() == 0 ){}
  int ag = Serial.parseInt(SKIP_ALL);
  Serial.println(ag);

  Serial.println("Enter Blue delay:");
  while (Serial.available() == 0 ){}
  int ab = Serial.parseInt(SKIP_ALL);
  Serial.println(ab);

  Serial.println("Enter loop duration:");
  while (Serial.available() == 0 ){}
  int l = Serial.parseInt(SKIP_ALL);
  Serial.println(l);
  
  for (i, b; (i < l/2) && b < 255; i++, b++){

    pixels.setBrightness(b);

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

  for ( i, b; (i > 0) && b > 0; i--, b--){
    pixels.setBrightness(b);

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
    i = 0;
    b = 0;
    Serial.end();
}
