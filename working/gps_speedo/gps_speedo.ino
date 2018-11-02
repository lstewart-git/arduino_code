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
les_button myButton(350, 7);
les_pot myPot(69);

//instantiate an oled_display object
#define OLED_RESET 12
Adafruit_SSD1306 les_screen(OLED_RESET);

//instantiate a gps object
static const int RXPin = 7, TXPin = 6;
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;

//instantiate a software serial object
SoftwareSerial ss(RXPin, TXPin);

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
      if (gps.location.isValid()) displayInfo();
	  if (!gps.location.isValid()) displayPreFix();
      }

  myButton.Update();
  myLED.Update();
       
 } // ////////////////  END MAIN PROGRAM LOOP

void displayInfo()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
    les_screen.println("Lattitude: ");
    les_screen.println(gps.location.lat(), 4);
    les_screen.println("Longitude: ");
    les_screen.println(gps.location.lng(), 4);
    les_screen.setTextSize(2);
    les_screen.println(gps.speed.kmph(), 2);
    les_screen.display();
} // END displayInfo() FUNCTION

void displayPreFix(){
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.println("NO FIX");
    les_screen.print("Mode: ");
    les_screen.println(myButton.state_flag);
    les_screen.println(gps.time.second());
    les_screen.println("Line 4");
    les_screen.display();
}

void show_logo(){
  les_screen.clearDisplay();
  les_screen.setTextSize(1);
  les_screen.setTextColor(WHITE);
  les_screen.setCursor(0,0);
  les_screen.println("Hello, Everett!");
  les_screen.display();
}
// END PROGRAM
