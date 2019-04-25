// * * * * * * * * * * * * *
// NewCallFunctions
// * * * * * * * * * * * * *
#include <Adafruit_NeoPixel.h>
#include <neopixel_functions.h>

#define PIN 6
#define NUM_LEDS 16
#define BRIGHTNESS 50


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, PIN,NEO_GRBW + NEO_KHZ800);
void cwc(Adafruit_NeoPixel & pixels);

void setup() {
  pixels.begin();
  pixels.setBrightness(15); // 1/3 brightness
}

void loop() {
  cwc(pixels);
}
