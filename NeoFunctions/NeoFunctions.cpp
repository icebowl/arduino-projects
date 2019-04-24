/*
  Morse.cpp - Library for flashing Morse code.
  Created by David A. Mellis, November 2, 2007.
  Released into the public domain.
*/

#include "Arduino.h"
#include "NeoFunctions.h"

NeoFunctions::NeoFunctions(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void NewoFunctions::cwc()
	{	int i; int w =0;
		for(i = 0; i < 16 ; i++){
			  //    strip.setPixelColor(pin number , strip.Color( red value,green value , blue value ,white value ) );
			  strip.setPixelColor(i, strip.Color(0,0,0,w ) );     
		}
	 strip.show();
	 delay(30);
	  w++;
	  if  (w > 255) w = 0;
	} 

void NewoFunctions::clear()
{
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}




