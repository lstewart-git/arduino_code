
#include "Arduino.h"

#include "les_button.h" 


les_button::les_button(int debounce){

    #define BUTT_PIN 2
	toggle_state_flag = 0;
	debounce_millis = debounce;
}

  void les_button::Setup()
  {
	 pinMode(BUTT_PIN, INPUT); 
  }


  void les_button::Update()
  {
    // check to see if it's time to change the state of the LED
	
    unsigned long currentMillis = millis();
	int buttval = digitalRead(BUTT_PIN);
	
	if (currentMillis > last_press_time + debounce_millis){
		
		if (buttval == HIGH) {
			last_press_time = currentMillis;
			if (toggle_state_flag == 1) toggle_state_flag = 0;
			else toggle_state_flag = 1;
			}
		}
	
   }



