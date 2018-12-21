/*
les potentiometer driver
this potentiometer maintains internal
state which can be queried

 */

#ifndef les_pot_h
#define les_pot_h
#include "Arduino.h"

class les_pot{

	public:
		// seems constructors with no arguments dont work with arduino compiler
		les_pot (int crapval);
		void Setup ();
		void Update ();
		int pot_value;

};


#endif
