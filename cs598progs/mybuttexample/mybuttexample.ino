#include <les_rgb_led.h>
#include <les_button.h>

//Variables
les_rgb_led myLED(100,100);
les_button myButton(200);

void setup() {
 Serial.begin(9600);
 digitalWrite(13, LOW);
 myLED.Setup();
 myButton.Setup();
 myLED.SetColor(50, 50, 50);
 myLED.SetOn();
}

void loop(){
  Serial.println(myButton.toggle_state_flag);
  myButton.Update();
  myLED.Update();
  if (myButton.toggle_state_flag == 1){
    myLED.SetOff();
    myLED.SetColor(random(254), random(254), random(254));
   }
     if (myButton.toggle_state_flag == 0){
    myLED.SetOn();
   }
  }
  
 
