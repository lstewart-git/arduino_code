/*
les autopilot

 */

#ifndef les_autopilot_h
#define les_autopilot_h
#include "Arduino.h"

// define Autopilot class
class les_Autopilot{

	public:
		// seems constructors with no arguments dont work with arduino compiler
		les_Autopilot (int);
		void Setup ();
		void Update ();
		int mode;

  };


#endif
