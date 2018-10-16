
// CS 598 Assignment #3
// by Lawrence E Stewart
// Oct 17, 2018

// include libraries which abstract components
// on my breadboard

// custom libraries
#include <les_rgb_led.h>
#include <les_button.h>

// 3rd party libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// program control logic variable
int mode_counter = 0;

// instantiate class instances
les_rgb_led myLED(100);
les_button myButton(250, 6);
Adafruit_SSD1306 les_screen(12);

// call class setup routines
void setup() {
 les_screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 myLED.Setup();
 myButton.Setup();
 ShowLogo(); 
}

// MAIN LOOP
// the button object keeps track of an internal state
// (made public for simplicity, not good practice)
// from 0 to 6, which are the index values of the
// color codes built in to the les_rgb_led object
void loop(){
  myButton.Update();
  myLED.Update();
  
  // don't do anything until state changes
  if (myButton.state_flag != mode_counter){
    myLED.ShowColor(myButton.state_flag);
    mode_counter = myButton.state_flag;
    ShowMode(mode_counter);}
   }
   
// END MAIN LOOP

void ShowLogo(){
  les_screen.clearDisplay();
  les_screen.setTextSize(1);
  les_screen.setTextColor(WHITE);
  les_screen.setCursor(0,0);
  les_screen.println("Lawrence Stewart");
  les_screen.println("CS 598 Assignment #3");
  les_screen.println("October 16, 2018");
  les_screen.display();
}

void ShowMode(int mode_counter){
  les_screen.clearDisplay();
  les_screen.setCursor(25,13);
  les_screen.setTextSize(2);
  if (mode_counter==1)les_screen.println("RED");
  if (mode_counter==2)les_screen.println("ORANGE");
  if (mode_counter==3)les_screen.println("YELLOW");
  if (mode_counter==4)les_screen.println("GREEN");
  if (mode_counter==5)les_screen.println("BLUE");
  if (mode_counter==6)les_screen.println("VIOLET");
  les_screen.display();
}


 
