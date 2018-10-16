
#include "Arduino.h"

#include "les_button.h"


les_button::les_button(int debounce){

  #define BUTT_PIN 2
	state_flag = 0;
	debounce_millis = debounce;
}

  void les_button::Setup()
  {
	 pinMode(BUTT_PIN, INPUT);
  }


  void les_button::Update()
  {
    // check to see if it's time to change internal state
  unsigned long currentMillis = millis();
	int buttval = digitalRead(BUTT_PIN);
	// check that debounce timer fm last press expired
	if (currentMillis > last_press_time + debounce_millis){

		if (buttval == HIGH) {     // button is pressed
			last_press_time = currentMillis;
      state_flag ++;  // increment the 'state' or 'mode'
      // recycle state to 1, state 0 is the startup state
			if (state_flag >= 7) state_flag = 1;
			}
		}
   }
