/*
 Fading
 
 This example shows how to fade an LED using the analogWrite() function.
 
 The circuit:
 * LED attached from digital pin 9 to ground.
 
 Created 1 Nov 2008
 By David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe
 
 http://arduino.cc/en/Tutorial/Fading
 
 This example code is in the public domain.
 
 */


int RedledPin = 3;    // LED connected to digital pin 9
int GreenledPin = 5;    // LED connected to digital pin 9
int BlueledPin = 6;    // LED connected to digital pin 9

void setup()  { 
  // nothing happens in setup 
} 

void loop()  { 
  // fade in from min to max in increments of 5 points:
  int red = random (3);
  int green = random (3);
  int blue = random (3);
  int delayTime = 5;
  int i;

    analogWrite(RedledPin, red*50); 
   
    analogWrite(GreenledPin, green*50); 
        analogWrite(BlueledPin, blue*50); 
    delay(350);
 
}


