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
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <les_rgb_led.h>
#include <les_button_v2.h>
#include <les_pot.h>

//instantiate breadboard objects
les_rgb_led myLED(100);
les_button_v2 myButton(350, 5);
les_pot myPot(69);

//oled_display object
#define OLED_RESET 12
Adafruit_SSD1306 les_screen(OLED_RESET);

//gps object
static const int RXPin = 7, TXPin = 6;
static const uint32_t GPSBaud = 9600;
static const double HOME_LAT = 39.454233, HOME_LON = -77.384811; 
TinyGPSPlus gps;

//software serial object
SoftwareSerial ss(RXPin, TXPin);

// program logic variables
double distanceToHome = 0.0;
double distanceMiles = 0.0;
double max_distance = 0.0;
float max_speed = 0.0;
float cur_speed = 0.0;

//  /////////////  SETUP  ////////////////////
void setup()
{
  ss.begin(GPSBaud);
  les_screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  myLED.Setup();
  myButton.Setup();
  myPot.Setup();
  show_logo();
}
//   ///////////////// MAIN PROGRAM LOOP
void loop()
{
  while (ss.available() > 0)
	  
    if (gps.encode(ss.read())){
      
        distanceToHome = TinyGPSPlus::distanceBetween(
          gps.location.lat(),
          gps.location.lng(),
          HOME_LAT, 
          HOME_LON);
          
       distanceMiles = distanceToHome / 1609.344;
       // check for new max distance
       if (distanceMiles > max_distance) max_distance = distanceMiles;

       cur_speed = gps.speed.kmph();
       // check for new high speed
       if (cur_speed > max_speed) max_speed = cur_speed;
         
      if (myButton.state_flag == 1) displayLocation();
      if (myButton.state_flag == 2) displayDistance();
      if (myButton.state_flag == 3) displaySpeed();
      if (myButton.state_flag == 4) displayMax();
	      }

  myButton.Update();
  myLED.Update();
       
 } // ////////////////  END MAIN PROGRAM LOOP

void displayDistance()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
          
        double courseToHome =
        TinyGPSPlus::courseTo(
          gps.location.lat(),
          gps.location.lng(),
          HOME_LAT, 
          HOME_LON);
  

    if (distanceToHome < 200 ){     
      les_screen.println("Distance to Home:");
      les_screen.print(distanceToHome, 0);
      les_screen.println(" meters");
    }
    else{
      les_screen.println("Distance to Home:");
      les_screen.print(distanceToHome / 1609.344, 2);
      les_screen.println(" miles"); 
    }
      
    les_screen.print("Course: ");      
    les_screen.println(courseToHome, 1);
    les_screen.display();
} // END displayDistance() FUNCTION


void displayLocation()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
    les_screen.println("Location:");
    les_screen.print("Lat:  ");
    les_screen.println(gps.location.lat(),3);
    les_screen.print("Long: ");
    les_screen.println(gps.location.lng(), 3);
    les_screen.display();

} // END displayLocation() FUNCTION

void displaySpeed()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
    les_screen.println("Speed:");
    les_screen.setTextSize(2);
    les_screen.print(cur_speed, 2);
    les_screen.print(" kph");
    les_screen.display();
} // END displaySpeed() FUNCTION

void displayMax()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
    les_screen.print("Max Speed:");
    les_screen.print(max_speed, 2);
    les_screen.println(" kph");
    les_screen.print("Max Distance:");
    les_screen.print(max_distance, 2);
    les_screen.println(" mi");
    les_screen.display();
} // END displayMax() FUNCTION


void show_logo(){
  les_screen.clearDisplay();
  les_screen.setTextSize(1);
  les_screen.setTextColor(WHITE);
  les_screen.setCursor(0,0);
  les_screen.println("GPS Interface");
  les_screen.println("By Lawrence Stewart");
  les_screen.println("   Press Button");
  les_screen.println("     to Begin");
  les_screen.display();
}
/*
void play_tone1(int hz1, int hz2){
  tone(buzz_pin, hz1);
  delay(500);
  noTone(buzz_pin);
  tone(buzz_pin, hz2);
  delay(500);
  noTone(buzz_pin);}
*/

  
// END PROGRAM
