/*
les rgb led driver
 */


#ifndef les_rgb_led_h


#define les_rgb_led_h

#include "Arduino.h"


class les_rgb_led{

	public:


		les_rgb_led(byte unused);
		void Update ();
		void Setup ();
		void SetColor(int rp, int gp, int bp);
		void SetOn ();
		void SetOff ();
    void ShowColor(int colorcode);
		void SetFlipTime (int flip_interval_ms);
		void FlipOn();
		void FlipOff();


	// private:

    int built_in_colors [7][3] =
    {{0,0,0},      //  index 0 OFF
     {255,0,0},      //  index 1 RED
     {255,90,0},      //  index 2 ORANGE
     {255,255,0},    //  index 3 YELLOW
     {0,255,0},      //  index 4 GREEN
     {0,0,255},      //  index 5 BLUE
     {110,25,110}};   //  index 6 VIOLET

    int RedPower;
    int GreenPower;
    int BluePower;
	int FlipTimer;
	int FlipFlag;
	unsigned long last_flip_time;
	int flip_color;

};

//	The end wrapping of the #ifndef Include Guard
#endif
