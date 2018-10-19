// CS 598 Assignment #4
// by Lawrence E Stewart
// Oct 19, 2018

// include libraries which abstract components
// on my breadboard

// custom libraries
#include <les_rgb_led.h>
#include <les_button.h>
#include <les_scanner.h>

// 3rd party libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// program control logic variable
int mode_counter = 0;

// instantiate class instances
les_scanner larson(50);
les_rgb_led myLED(100);
les_button myButton(250, 7);
Adafruit_SSD1306 les_screen(12);

// call class setup routines
void setup() {
 les_screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 myLED.Setup();
 myButton.Setup();
 larson.Setup();
}

// MAIN LOOP
// the button object keeps track of an internal state
// (made public for simplicity, not good practice)
// from 0 to 6, which are the index values of the
// color codes built in to the les_rgb_led object
void loop(){
  myButton.Update();
  myLED.Update();
  larson.Update();

  // don't do anything until state changes
  if (myButton.state_flag != mode_counter){
    myLED.ShowColor(myButton.state_flag);
    mode_counter = myButton.state_flag;
    // ShowMode(mode_counter);}
   }

// END MAIN LOOP
