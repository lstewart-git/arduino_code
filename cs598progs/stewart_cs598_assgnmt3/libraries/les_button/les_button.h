/*
les button driver
 */


#ifndef les_button_h


#define les_button_h

#include "Arduino.h"


class les_button{

	public:
		les_button (int debounce_millis);
		void Setup ();
		void Update ();
		int state_flag;

	private:
		unsigned long debounce_millis;
		unsigned long last_press_time = 0;
};

//	The end wrapping of the #ifndef Include Guard
#endif
