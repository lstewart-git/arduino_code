
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
#include <les_photoresistor.h>

//instantiate breadboard objects
les_rgb_led myLED(100);
les_button myButton(350, 4);
les_pot myPot(69);
les_photoresistor myCDS(A1);

const int light_pin = A1;
int light_val = 0;
int maxval = 0;
int minval = 1024;
int light_on = 800;

//instantiate an oled_display object
#define OLED_RESET 12
Adafruit_SSD1306 les_screen(OLED_RESET);


static const int relay_pin = 12;
void setup()
{
  // for buzzer
  pinMode(relay_pin, OUTPUT);
 les_screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  myLED.Setup();
 myButton.Setup();
  myPot.Setup();
  myCDS.Setup();
  show_logo();


}
//   ///////////////// MAIN PROGRAM LOOP
void loop()
{
      light_val = myCDS.photoresistor_value;
      if (light_val > maxval) maxval = light_val;
      if (light_val < minval) minval = light_val;
      
      // light is off inside
      if (light_val < light_on){
       myLED.SetOff();
      }
      
      // light is on inside
      else {
        myLED.SetColor(255, 0, 255);
        myLED.SetOn();
      }

      // pick a screen to display
      if ( myButton.state_flag == 1) display_mode1();
      if ( myButton.state_flag == 2) display_mode_off();
	

  myButton.Update();
  myLED.Update();
  myCDS.Update();
       
 } // ////////////////  END MAIN PROGRAM LOOP

void display_mode1()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
    les_screen.print("max: ");
    les_screen.print(maxval);
    les_screen.print("  min: ");
    les_screen.println(minval);
    les_screen.setTextSize(2);
    les_screen.println(light_val);
    les_screen.display();
} 

void display_mode_off()
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


// END PROGRAM
