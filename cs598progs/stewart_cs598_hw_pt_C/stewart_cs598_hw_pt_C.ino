// CS 598 Homwework part C
// by Lawrence Stewart
// Due November 15, 2018

// This program uses 2 photocells (my total supply)
// to control the color of an rgb led

// Arduino (Red Box) Connection Layout:
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
// digital pin 10 : 
// digital pin 11 : 
// digital pin 12 :
// digital pin 13 :
// analog pin 0 : potentiometer
// analog pin 1 : photoresistor 1
// analog pin 2 : photoresistor 2
// analog pin 3 :
// analog pin 4 : I2C SDA oled display
// analog pin 5 : I2C SCL oled display

// Libraries
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
les_photoresistor my_cds_1(A1);

// program control variables
int light_val = 0;
int maxval = 0;
int minval = 1024;
int low_light_cutoff = 300;
int light_on = 1024;
int intensity = 0;
int potreading = 0;

//instantiate an oled_display object
#define OLED_RESET 12
Adafruit_SSD1306 les_screen(OLED_RESET);

void setup()
{
  les_screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  myLED.Setup();
  myButton.Setup();
  myPot.Setup();
  my_cds_1.Setup();
  show_logo();
}

//   ///////////////// MAIN PROGRAM LOOP /////////////
void loop()
{
      if (myButton.state_flag == 1){
        
        // get light sensor value
        light_val = my_cds_1.photoresistor_value;

        // get potentiometer value
        potreading = myPot.pot_value;

        // set cutoff value from pot input
        light_on = potreading;

        // track max and min values
        if (light_val > maxval) maxval = light_val;
        if (light_val < minval) minval = light_val;

        //turn on light at calculated intensity
        if (light_val < light_on){
          set_intensity();
          set_color_level();
          myLED.SetOn();
          mode1();
          }
      
        //turn off light
        else {
          myLED.SetOff();
          intensity = 0;
          mode1();
          }
        }
          
      if (myButton.state_flag == 2){
        myLED.SetOff();
        mode2();
      }
      
      myButton.Update();
      myLED.Update();
      myPot.Update();
      my_cds_1.Update();
       
 } // ////////////////  END MAIN PROGRAM LOOP

void mode1()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
    les_screen.print("max: ");
    les_screen.print(maxval);
    les_screen.print("  min: ");
    les_screen.println(minval);
    les_screen.setTextSize(2);
    les_screen.print("lux: ");
    les_screen.println(light_val);
    les_screen.setTextSize(1);
    les_screen.print("cut-in:");
    les_screen.print(potreading);
    les_screen.print(" level:");
    les_screen.println(intensity);
    les_screen.display();

} // END mode1() FUNCTION

void mode2()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(2);
    les_screen.println("Off:");
    les_screen.display();
} // END mode2() FUNCTION


void show_logo(){
  les_screen.clearDisplay();
  les_screen.setTextSize(1);
  les_screen.setTextColor(WHITE);
  les_screen.setCursor(0,0);
  les_screen.println("Homework Pt B");
  les_screen.println("By Lawrence Stewart");
  les_screen.println("   Press Button");
  les_screen.println("     to Begin");
  les_screen.display();
} // END show_logo() FUNCTION

void set_intensity(){
          // do a linear interpolation from ambient light range to brightness range
         // map(intensity, , potreading, 0, 255);
          intensity = map(light_val, low_light_cutoff, potreading, 0, 255);
          intensity = 255 - intensity;
          }

void set_color_level(){
  if (intensity > 200) myLED.SetColor(intensity, intensity, intensity);
  if (intensity > 150 && intensity <= 200) myLED.SetColor(0, 0, intensity);
  if (intensity > 100 && intensity <= 150) myLED.SetColor(0, intensity, 0);
  if (intensity > 50 && intensity <= 100) myLED.SetColor(intensity, 0, intensity);
  if (intensity <= 50) myLED.SetColor(intensity, 0, 0);

}

// END PROGRAM
