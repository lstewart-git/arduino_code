/*
les rgb led driver
 */


#ifndef les_rgb_led_h

                                           
#define les_rgb_led_h

#include "Arduino.h"


class les_rgb_led{

	public:
	
	
		les_rgb_led(long RedOnTime, long RedOffTime);
		void Update ();
		void Setup ();
		void SetColor(int rp, int gp, int bp);
		void SetOn ();
		void SetOff ();

	// private:    

		int _state;
	

};

//	The end wrapping of the #ifndef Include Guard
#endif
