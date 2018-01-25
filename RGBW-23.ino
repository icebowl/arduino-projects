// RGBW (Red Green Blue White Neo-Pixel starter code
// 16 LEDS  increment
// CW Coleman 170413

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

#define NUM_LEDS 24

#define BRIGHTNESS 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);


void setup() {
  Serial.begin(115200);
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

// Initialize some variables for the void loop()
int red = 0, green= 0, blue = 0, white = 10;
int wait = 500;
int led = 0;
int i;
   int out = 23;
void loop() {

  for ( led = 0; led < 7; led++){  
      red = 255, green= 0, blue = 0, white = 0;
      strip.setPixelColor(led, red, green , blue, white);
      strip.show();
      // out
      red = 0, green= 0, blue = 255, white = 10;
      strip.setPixelColor(out, red, green , blue, white);
      strip.show();
      red = 0, green= 0, blue = 255, white = 20;
      strip.setPixelColor(out-1, red, green , blue, white);
      strip.show();
      strip.setPixelColor(out-3, red, green , blue, white);
      delay(wait);
      red = 0, green= 0, blue = 0, white = 0;
      strip.setPixelColor(led, red, green , blue, white);
      strip.show();
      out = out - 1;
      if (out < 0) {out = 23; blue = blue - 100;}
      Serial.println(out);
  }//end of for loop
    
}


