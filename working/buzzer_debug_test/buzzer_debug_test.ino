
// Arduino Connection Layout:
// digital pin 0 : 
// digital pin 1 : 
// digital pin 2 : Button 1
// digital pin 3 : led blue
// digital pin 4 : Buzzer
// digital pin 5 : led red
// digital pin 6 : Tx Software Serial GPS
// digital pin 7 : Rx Software Serial GPS
// digital pin 8 : 
// digital pin 9 : led green
// digital pin 10 : SPI sd card reader
// digital pin 11 : SPI sd card reader
// digital pin 12 : SPI sd card reader
// digital pin 13 : SPI sd card reader
// analog pin 0 : potentiometer
// analog pin 1 :
// analog pin 2 :
// analog pin 3 :
// analog pin 4 : I2C SDA oled display
// analog pin 5 : I2C SCL oled display


#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <les_rgb_led.h>
#include <les_button.h>
#include <les_pot.h>

//instantiate breadboard objects
les_rgb_led myLED(100);
les_button myButton(350, 5);
les_pot myPot(69);

//instantiate an oled_display object
#define OLED_RESET 12
Adafruit_SSD1306 les_screen(OLED_RESET);


static const int buzz_pin = 4;
void setup()
{
  // for buzzer
  pinMode(buzz_pin, OUTPUT);
 les_screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  myLED.Setup();
 myButton.Setup();
  myPot.Setup();
  show_logo();


}
//   ///////////////// MAIN PROGRAM LOOP
void loop()
{

      if ( myButton.state_flag == 1) tone1();
      if ( myButton.state_flag == 2) tone2();
      if ( myButton.state_flag == 3) tone3();
      if ( myButton.state_flag == 4) tone4();
	

  myButton.Update();
  myLED.Update();
       
 } // ////////////////  END MAIN PROGRAM LOOP

void tone1()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
    les_screen.println("Tone 1:");
    les_screen.display();
    play_tone1(440, 880);
} // END displayDistance() FUNCTION


void tone2()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
    les_screen.println("Tone2: ");
    les_screen.display();
    play_tone1(50, 1500);
    
} // END displayLocation() FUNCTION

void tone3()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
    les_screen.println("Tone3:");
    les_screen.display();
    play_tone1(200, 6000);
} // END displaySpeed() FUNCTION

void tone4()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(2);
    les_screen.println("Off:");
    les_screen.display();
}


void show_logo(){
  les_screen.clearDisplay();
  les_screen.setTextSize(1);
  les_screen.setTextColor(WHITE);
  les_screen.setCursor(0,0);
  les_screen.println("Tone Test");
  les_screen.println("By Lawrence Stewart");
  les_screen.println("   Press Button");
  les_screen.println("     to Begin");
  les_screen.display();
}

void play_tone1(int hz1, int hz2){
  tone(buzz_pin, hz1);
  delay(500);
  noTone(buzz_pin);
  tone(buzz_pin, hz2);
  delay(500);
  noTone(buzz_pin);}

  void play_tone2(int hz1, int hz2){
  tone(buzz_pin, hz1, 500);
  tone(buzz_pin, hz2, 500);
  }
// END PROGRAM
