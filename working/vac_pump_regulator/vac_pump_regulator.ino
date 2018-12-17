
// Arduino Connection Layout:
// digital pin 0 : 
// digital pin 1 : 
// digital pin 2 : Button 1
// digital pin 3 : Button 2
// digital pin 4 : 
// digital pin 5 : 
// digital pin 6 : Tx Software Serial GPS
// digital pin 7 : Rx Software Serial GPS
// digital pin 8 : 
// digital pin 9 : 
// digital pin 10 : 
// digital pin 11 : 
// digital pin 12 : pump power relay
// digital pin 13 : 
// analog pin 0 : 
// analog pin 1 : cds photocell
// analog pin 2 :
// analog pin 3 :
// analog pin 4 : I2C SDA oled display
// analog pin 5 : I2C SCL oled display


#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <les_button_v2.h>
#include <les_photoresistor.h>

//instantiate breadboard objects
les_button_v2 button1(2, 350, 3);  // mode changer
les_button_v2 button2(5, 350, 11);  // reflects trigger level in state flag
les_photoresistor myCDS(A1);

const int light_pin = A1;  // cds
static const int relay_pin = 12; // pump power relay
int light_val = 0;         // current cds reading
int maxval = 0;
int minval = 1024;
int trigger_level = 800;   // detect a light on event at this level
int total_pump_cycles = 0;


//instantiate an oled_display object
#define OLED_RESET 12
Adafruit_SSD1306 les_screen(OLED_RESET);

//   ////////////    SETUP     ///////////////////
void setup()
{
  pinMode(relay_pin, OUTPUT);
  digitalWrite(relay_pin, LOW);
  les_screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  button1.Setup();
  button2.Setup();
   myCDS.Setup();
  show_logo();


}
//   ///////////////// MAIN PROGRAM LOOP
void loop()
{
      // make sure relay off in startup mode
      if ( button1.state_flag == 0) digitalWrite(relay_pin, LOW);

      // update and read all components
      light_val = myCDS.photoresistor_value;
      button1.Update();
       myCDS.Update();

      // keep track of light vals
      if (light_val > maxval) maxval = light_val;
      if (light_val < minval) minval = light_val;

      // check for operational mode:
      if ( button1.state_flag == 1){
   
        // light is off inside
        if (light_val < trigger_level){
          digitalWrite(relay_pin, LOW); // turn off pump
         }
      
        // light is on inside
        else {
        digitalWrite(relay_pin, HIGH); // turn on pump
        }

     } // end operational mode check

     
      // pick a screen to display
      if ( button1.state_flag == 1) display_mode1();
      if ( button1.state_flag == 2) display_mode_off();
	

  button1.Update();
  button2.Update();
  myCDS.Update();
  trigger_level = button2.state_flag * 101;  // change the trigger level as necc
        
 } // ////////////////  END MAIN PROGRAM LOOP

void display_mode1()
{
    les_screen.clearDisplay();
    les_screen.setCursor(0,0);
    les_screen.setTextSize(1);
    les_screen.print("max:");
    les_screen.print(maxval);
    les_screen.print(" min:");
    les_screen.println(minval);
    les_screen.print("trigger level:");
    les_screen.println(trigger_level);
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
  les_screen.println("Pump Regulator");
  les_screen.println("By Lawrence Stewart");
  les_screen.println("   Press Button");
  les_screen.println("     to Begin");
  les_screen.display();
}


// END PROGRAM
