 // Software for a prototype GPS device
// An Arduino Experiment
// by Lawrence Stewart

// Arduino Connection Layout:
// digital pin 0 : 
// digital pin 1 : 
// digital pin 2 : Button 1
// digital pin 3 : led blue
// digital pin 4 : 
// digital pin 5 : led red
// digital pin 6 : Tx Software Serial GPS
// digital pin 7 : Rx Software Serial GPS
// digital pin 8 : 
// digital pin 9 : led green
// digital pin 10 : 
// digital pin 11 : 
// digital pin 12 : 
// digital pin 13 : 
// analog pin 0 : potentiometer
// analog pin 1 :
// analog pin 2 :
// analog pin 3 :
// analog pin 4 : I2C SDA oled display
// analog pin 5 : I2C SCL oled display

// LIBRARIES

static const int buzz_pin = 5;
//  /////////////  SETUP  ////////////////////
void setup()
{
  pinMode(buzz_pin, OUTPUT);
  play_tone1(1000, 2000);
}

//   ///////////////// MAIN PROGRAM LOOP
void loop()
{


       
 } // ////////////////  END MAIN PROGRAM LOOP





void play_tone1(int hz1, int hz2){
  tone(buzz_pin, hz1);
  delay(500);
  noTone(buzz_pin);
  tone(buzz_pin, hz2);
  delay(500);
  noTone(buzz_pin);}


  
// END PROGRAM
