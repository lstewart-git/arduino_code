#include <les_rgb_led.h>
#include <les_button.h>

//Variables
les_rgb_led myLED(100);
les_button myButton(150);

void setup() {
 myLED.Setup();
 myButton.Setup();
}

void loop(){
  myButton.Update();
  myLED.Update();
  myLED.ShowColor(myButton.state_flag);

  }
  
 
