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


static const int buzz_pin = 8;
void setup()
{
  // for buzzer
  pinMode(buzz_pin, OUTPUT);

  
 // ss.begin(GPSBaud);
 les_screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  myLED.Setup();
 myButton.Setup();
  myPot.Setup();
  show_logo();


}
//   ///////////////// MAIN PROGRAM LOOP
void loop()
{


      if ( myButton.state_flag == 1) displayLocation();
      if ( myButton.state_flag == 2) displayDistance();
      if ( myButton.state_flag == 3) displaySpeed();
	

  myButton.Update();
  myLED.Update();
       
 } // ////////////////  END MAIN PROGRAM LOOP

void displayDistance()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
  
      les_screen.println("Distance to Home:");
 
    les_screen.display();
        tone(buzz_pin, 440);
  delay(500);
  noTone(buzz_pin);
  tone(buzz_pin, 880);
  delay(500);
  noTone(buzz_pin);
} // END displayDistance() FUNCTION


void displayLocation()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
      les_screen.println("Long: ");
       les_screen.display();
           tone(buzz_pin, 220);
  delay(500);
  noTone(buzz_pin);
  tone(buzz_pin, 880);
  delay(500);
  noTone(buzz_pin);
    
} // END displayLocation() FUNCTION

void displaySpeed()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
    les_screen.println("Speed:");
    les_screen.display();
        tone(buzz_pin, 120);
  delay(500);
  noTone(buzz_pin);
  tone(buzz_pin, 2200);
  delay(500);
  noTone(buzz_pin);
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
     tone(buzz_pin, 440);
  delay(500);
  noTone(buzz_pin);
  tone(buzz_pin, 880);
  delay(500);
  noTone(buzz_pin);

 
}
// END PROGRAM
