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
int dial[5] = {0,0,0,0,1};
void loop() {
  neo_black(0,0,0,0,16);
  dial[0] = random(0, 16);
  dial[1] = random(0, 16);
  dial[2] = random(0, 16);
  dial[3] = random(0, 16);
  dial[4] = random(0,2);
  if (dial[4] == 0){dial[4] = -1; }//set parity -1 or 1
   Serial.println("* * main loop * * ");
  for (i = 0; i < 5; i ++){Serial.print(dial[i]); Serial.print(" ");delay(1);}
    Serial.println("* * main loop * *\n");
  neo_dial(dial); 
  
  
}
int l = 0 ;
int count;
int done;
int parity = 1;
int swap;
void neo_dial (int ndial[] ){
    done = 0;
    swap = 0;
    wait = 100;
    count = 0;
    strip.setBrightness(100);
    l = ndial[0];
    parity = ndial[4];
    while (done == 0 ){
        if( swap == 0){red = 255; green = 0; blue = 0; white = 10;}
        if( swap == 4){red = 0; green = 127; blue = 255; white = 10;}
        strip.setPixelColor(l, red, green , blue, white);
        strip.show();
        delay(wait);
        if (swap == 0){  red = 0; green = 0; blue = 0; white = 0;}
        if (swap == 1){  red = 0; green = 255; blue = 0; white = 10;}
        if (swap == 2){  red = 0; green = 0; blue = 255; white = 10;}
        if (swap == 3){  red = 255; green = 255; blue = 0; white = 10;}
     
        strip.setPixelColor(l, red, green , blue, white);
        strip.show();
       // delay(wait);
         l= l + parity;
           if (l > 15) l = 0;
        if (l < 0 ) l = 15;
        if (l == ndial[0] && swap == 0){parity = parity * -1;swap = 1; }
         if (l == ndial[1] && swap == 1){parity = parity * -1;swap = 2;}
          if (l == ndial[2] && swap == 2){parity = parity * -1;swap = 3;}
           if (l == ndial[3] && swap == 3){parity = parity * -1;done = 1;}
           Serial.print(" ");
           Serial.print(l);
           if (count % 16 == 0 )Serial.println(); 
           count++;
    }


}

void neo_black (int r, int g, int b, int w, int led ){
    //n is the led
    for (int n = 0; n < led;n++){
      strip.setPixelColor(n, r, g , b, w);
      strip.show();
    }

//Serial.print(" BLACK ");

}
