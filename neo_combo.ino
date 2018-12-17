// RGBW - neo_combo
// CW Coleman 181214 a
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6
#define NUM_LEDS 16
#define BRIGHTNESS 50

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);


void setup() {
  Serial.begin(115200);
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  randomSeed(analogRead(0));
}

// Initialize some variables for the void loop()
// global vaiables
int i, led, red, green, blue, white;
int start , one, two, three, wait;
int count = 0;
int dial[5] = {0,0,0,0,1};
void loop() {
  neo_black(0,0,0,0,16);
  dial[0] = random(0, 16);
  dial[1] = random(0, 16);
  dial[2] = random(0, 16);
  dial[3] = random(0, 16);
  dial[4] = random(0,2);
  if (dial[4] == 0){dial[4] = -1; }//set parity -1 or 1
  for (i = 0; i < 5; i ++){Serial.print(dial[i]); Serial.print(" ");delay(1);}
    Serial.println("* * main loop * *");
  neo_dial(dial); 
  
  
}
int l = 0 ;
int done;
int parity = 1;
void neo_dial (int ndial[] ){
    done = 0;
    count = 0;
    wait = 50;
    strip.setBrightness(100);
    l = ndial[0];
    parity = ndial[4];
    while (done == 0 ){
        red = 255; green = 0; blue = 0; white = 10;
        strip.setPixelColor(l, red, green , blue, white);
        strip.show();
        delay(wait);
        if (count < 16 && count > -1){  red = 0; green = 0; blue = 0; white = 0;}
        if (count > 16 && count < 33){  red = 0; green = 255; blue = 0; white = 10;}
        if (count > 32 && count < 49){  red = 0; green = 0; blue = 255; white = 10;}
        if (count > 48 && count < 65){  red = 255; green = 255; blue = 255; white = 10;}
        strip.setPixelColor(l, red, green , blue, white);
        strip.show();
       // delay(wait);
         l= l + parity;
        if (l > 15) l = 0;
        if (l < 0 ) l = 15;
        if (count % 16 == 0)parity = parity * -1;
        count++;
        if (count > 65) done = 1;
    }


}

void neo_black (int r, int g, int b, int w, int led ){
    //n is the led
    for (int n = 0; n < led;n++){
      strip.setPixelColor(n, r, g , b, w);
      strip.show();
    }

Serial.print(" BLACK ");
Serial.println(r);

}
