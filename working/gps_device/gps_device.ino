#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <les_rgb_led.h>
#include <les_button.h>
#include <les_pot.h>

//instantiate breadboard objects
les_rgb_led myLED(100);
les_button myButton(350, 4);
les_pot myPot(69);

//instantiate an oled_display object
#define OLED_RESET 12
Adafruit_SSD1306 les_screen(OLED_RESET);

//instantiate a gps object
static const int RXPin = 7, TXPin = 6;
static const uint32_t GPSBaud = 9600;
static const double HOME_LAT = 39.454233, HOME_LON = -77.384811; 
TinyGPSPlus gps;

//instantiate a software serial object
SoftwareSerial ss(RXPin, TXPin);
static const int buzz_pin = 8;
void setup()
{
  // for buzzer
  pinMode(buzz_pin, OUTPUT);
      tone(buzz_pin, 440);
  delay(500);
  noTone(buzz_pin);
  tone(buzz_pin, 880);
  delay(500);
  noTone(buzz_pin);
  
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
      if (gps.location.isValid() && myButton.state_flag == 1) displayLocation();
      if (gps.location.isValid() && myButton.state_flag == 2) displayDistance();
      if (gps.location.isValid() && myButton.state_flag == 3) displaySpeed();
	      }

  myButton.Update();
  myLED.Update();
       
 } // ////////////////  END MAIN PROGRAM LOOP

void displayDistance()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
   
          double distanceToHome =
        TinyGPSPlus::distanceBetween(
          gps.location.lat(),
          gps.location.lng(),
          HOME_LAT, 
          HOME_LON);
          
        double courseToHome =
        TinyGPSPlus::courseTo(
          gps.location.lat(),
          gps.location.lng(),
          HOME_LAT, 
          HOME_LON);
  
    double distanceMiles = distanceToHome / 1609.344;
      
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
    les_screen.print(gps.speed.kmph(), 2);
    les_screen.print(" kph");
    les_screen.display();
} // END displaySpeed() FUNCTION


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
  // play a tune

 
}
// END PROGRAM
