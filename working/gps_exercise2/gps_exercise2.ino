#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 12
Adafruit_SSD1306 les_screen(OLED_RESET);
/*
   This sample sketch demonstrates the normal use of a TinyGPS++ (TinyGPSPlus) object.
   It requires the use of SoftwareSerial, and assumes that you have a
   4800-baud serial GPS device hooked up on pins 4(rx) and 3(tx).
*/
static const int RXPin = 7, TXPin = 6;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  ss.begin(GPSBaud);


  les_screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  les_screen.clearDisplay();
  les_screen.setTextSize(1);
  les_screen.setTextColor(WHITE);
  les_screen.setCursor(0,0);
  les_screen.println("Hello, Everett!");
  les_screen.display();
}

void loop()
{
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10)
  { while(true);}  // IDLE IF NO GPS COMM AFTER 5 SEC
} // END LOOP

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

} // END FUNCTION
