// CS 598 assignment 6 part 2
// by Lawrence Stewart
// Due November 15, 2018

// This program controls an rgb LED 
// as a color mixing lamp. 
// the project in the exercise book includes
// three phototransistors to control 3 colors
// (r,g, and b), however I have 0 phototransistors
// and only 2 photoresistors available currently
// so my implementation will use photoresistors
// and a button, to allow selection of multiple
// 2 color sets
// the pwm values are limited to 155 instead of 255
// because this gives a more readily apparent
// dimming effect to human eyesight, high pwm
// values seem to get 'washed out'


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
// analog pin 1 : photoresistor #1
// analog pin 2 : photoresistor #2
// analog pin 3 :
// analog pin 4 : I2C SDA oled display
// analog pin 5 : I2C SCL oled display

// Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <les_rgb_led.h>
#include <les_button.h>

//instantiate breadboard objects
les_rgb_led myLED(100);
les_button myButton(350, 5);

// light sensor pins
const int light_pin = A1;
const int light_pin_2 = A2;

// program control variables
int light_val = 0;
int light_val_2 = 0;
int intensity = 0;
int intensity_2 = 0;

//instantiate an oled_display object
#define OLED_RESET 12
Adafruit_SSD1306 les_screen(OLED_RESET);

void setup()
{
  les_screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  myLED.Setup();
  myButton.Setup();
  show_logo();
}

//   ///////////////// MAIN PROGRAM LOOP /////////////
void loop()
{
      if (myButton.state_flag != 0 && myButton.state_flag != 4){
        
        // get light sensor values
        light_val = analogRead(light_pin);
        light_val_2 = analogRead(light_pin_2);
        // show color and display
        set_intensity();
        set_color_level();
        myLED.SetOn();
        mode1();
        }
          
      if (myButton.state_flag == 4){
        myLED.SetOff();
        mode2();
      }
      
      myButton.Update();
      myLED.Update();
       
 } // ////////////////  END MAIN PROGRAM LOOP

void mode1()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
    les_screen.print("LV1: ");
    les_screen.print(light_val);
    les_screen.print("  LV2: ");
    les_screen.println(light_val_2);
    
   if (myButton.state_flag == 1){
    les_screen.print("  RED: ");
    les_screen.println(intensity);
    les_screen.print("  GREEN: ");
    les_screen.println(intensity_2);
   }

   if (myButton.state_flag == 2){
    les_screen.print("  RED: ");
    les_screen.println(intensity);
    les_screen.print("  BLUE: ");
    les_screen.println(intensity_2);
   }

   if (myButton.state_flag == 3){
    les_screen.print("  BLUE: ");
    les_screen.println(intensity);
    les_screen.print("  GREEN: ");
    les_screen.println(intensity_2);    
   }
    
    les_screen.display();
} // END mode1() FUNCTION

void mode2()
{
    les_screen.clearDisplay();
    les_screen.setCursor(10,10);
    les_screen.setTextSize(2);
    les_screen.println("Off:");
    les_screen.display();
} // END mode2() FUNCTION


void show_logo(){
  les_screen.clearDisplay();
  les_screen.setTextSize(1);
  les_screen.setTextColor(WHITE);
  les_screen.setCursor(0,0);
  les_screen.println("Cs598 ass#6 Pt 2");
  les_screen.println("By Lawrence Stewart");
  les_screen.println("   Press Button");
  les_screen.println("     to Begin");
  les_screen.display();
} // END show_logo() FUNCTION

void set_intensity(){
          // do a linear interpolation from hard-coded light range
          // to led brightness range, change light limits
          // here to tune for different environments
          intensity = map(light_val, 300, 800, 0, 155);
          intensity_2 = map(light_val_2, 970, 1016, 0, 155);
          if (intensity < 0) intensity = 0;
          if (intensity > 155) intensity = 155;
          if (intensity_2 < 0) intensity_2 = 0;
          if (intensity_2 > 155) intensity_2 = 155;
          }

void set_color_level(){
  // different color combinations mapped to button states
  if (myButton.state_flag == 1) myLED.SetColor(intensity, intensity_2, 0);
  if (myButton.state_flag == 2) myLED.SetColor(intensity, 0, intensity_2);
  if (myButton.state_flag == 3) myLED.SetColor(0, intensity_2, intensity);

}

// END PROGRAM
