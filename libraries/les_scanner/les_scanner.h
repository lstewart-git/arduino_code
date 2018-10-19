/*
les larson scanner driver


 */

#ifndef les_button_h
#define les_button_h
#include "Arduino.h"

class les_scanner{

	public:
		les_scanner (int debounce_millis, int modes);
		void Setup ();
		void Update ();



	private:

        int something;
};


#endif
