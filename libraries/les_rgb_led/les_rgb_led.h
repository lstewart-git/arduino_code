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
	long RedOnTime;     // milliseconds of on-time
	long RedOffTime;    // milliseconds of off-time
	int RedPower;

	long BlueOnTime;     // milliseconds of on-time
	long BlueOffTime;    // milliseconds of off-time
	int BluePower;

	long GreenOnTime;     // milliseconds of on-time
	long GreenOffTime;    // milliseconds of off-time
	int GreenPower;
	
	int RedState;             		// ledState used to set the LED
	unsigned long RedpreviousMillis;  	// will store last time LED was update
	
	int GreenState;             		// ledState used to set the LED
	unsigned long GreenpreviousMillis;  	// will store last time LED was update
	
	int BlueState;             		// ledState used to set the LED
	unsigned long BluepreviousMillis;  	// will store last time LED was update
	

};

//	The end wrapping of the #ifndef Include Guard
#endif
