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
		// also same with PlatformIO toolchain
		double init_pos_lat, init_pos_lon;
		double curr_pos_lat, curr_pos_lon;
		double prev_pos_lat, prev_pos_lon;
		float curr_heading;
		float desired_heading;
		int curr_waypoint; 
		bool init_fix_acquired = false;
		int mode; // acquiring, cruise, stop

		// methods
		les_Autopilot (int parameter);
		void Setup ();
		void Update ();
		

  };


#endif
