#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <les_rgb_led.h>
#include <les_button.h>

//instantiate breadboard objects
les_rgb_led myLED(100);
les_button myButton(350, 7);

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
  show_logo();
}
//   ///////////////// MAIN PROGRAM LOOP
void loop()
{
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();

  myButton.Update();
  myLED.Update();
  myLED.ShowColor(myButton.state_flag);
      
      
  // IDLE IF NO GPS COMM AFTER 5 SEC
  //if (millis() > 5000 && gps.charsProcessed() < 10)
  //{ while(true);}  
  
} // ////////////////  END MAIN PROGRAM LOOP

void displayInfo()
{
   if (gps.location.isValid())
  {
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
    les_screen.println(gps.location.lat(), 4);
    les_screen.println(gps.location.lng(), 4);
    les_screen.setTextSize(2);
    les_screen.println(gps.speed.kmph(), 2);
    les_screen.display();
  }
  else
  {
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.println("NO FIX");
    les_screen.display();
  }
} // END displayInfo() FUNCTION

void show_logo(){
  les_screen.clearDisplay();
  les_screen.setTextSize(1);
  les_screen.setTextColor(WHITE);
  les_screen.setCursor(0,0);
  les_screen.println("Hello, Everett!");
  les_screen.display();
}
// END PROGRAM
