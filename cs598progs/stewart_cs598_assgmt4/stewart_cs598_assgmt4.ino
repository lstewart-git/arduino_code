// CS 598 Assignment #4
// by Lawrence E Stewart
// Oct 19, 2018

// include libraries which abstract components
// on my breadboard

// custom libraries

#include <les_button.h>
#include <les_scanner.h>
#include <les_pot.h>

// 3rd party libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// program control logic variable
int mode_counter = 0;

// instantiate class instances
les_scanner larson(150);
les_button myButton(250, 4);
les_pot myPot(0);
Adafruit_SSD1306 les_screen(12);

// call class setup routines
void setup() {
 les_screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 myButton.Setup();
 myPot.Setup();
 larson.Setup();
 ShowLogo();
}

// MAIN LOOP

void loop(){
  myButton.Update();
  myPot.Update();
  // set the scanning speed:
  larson.cycle_time = myPot.pot_value/3;
  larson.Update();

  // don't do anything until state changes
  if (myButton.state_flag != mode_counter){
    mode_counter = myButton.state_flag;
    larson.current_mode = myButton.state_flag;
    ShowMode(mode_counter);}
   }

// END MAIN LOOP

void ShowLogo(){
  les_screen.clearDisplay();
  les_screen.setTextSize(1);
  les_screen.setTextColor(WHITE);
  les_screen.setCursor(0,0);
  les_screen.println("Lawrence Stewart");
  les_screen.println("CS 598 Assignment #4");
  les_screen.println("October 20, 2018");
  les_screen.display();
}

void ShowMode(int mode_counter){
  les_screen.clearDisplay();
  les_screen.setCursor(25,13);
  les_screen.setTextSize(2);
  if (mode_counter==1)les_screen.println("Mode 1");
  if (mode_counter==2)les_screen.println("Mode 2");
  if (mode_counter==3)les_screen.println("Mode 3");

  les_screen.display();
}
