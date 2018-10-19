/*
les larson scanner driver


 */

#ifndef les_button_h
#define les_button_h
#include "Arduino.h"

class les_scanner{

	public:
		les_scanner (int cycle_time);
		void Setup ();
		void Update ();
		void shiftDisplay(byte data);



	private:

        int cycle_time;
				unsigned long last_update;
				int current_position;
				byte array_argument;
};


#endif
