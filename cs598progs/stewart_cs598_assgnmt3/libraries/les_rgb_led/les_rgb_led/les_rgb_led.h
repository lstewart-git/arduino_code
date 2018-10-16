/*
les rgb led driver
 */


#ifndef les_rgb_led_h

                                           
#define les_rgb_led_h

#include "Arduino.h"


class les_rgb_led{

	public:
	
	
		les_rgb_led(int crapvar);
		
	
		void red_on();  
        void green_on(); 
        void blue_on(); 
        void white_on(); 
        void yellow_on(); 
        void purple_on(); 

            
		void all_off();
		void flash_white(int delayTime);
        void flash_red(int delayTime);
        void flash_blue(int delayTime);
        void flash_green(int delayTime);

	// private:                  
	bool _red_on;
    bool _green_on;
    bool _blue_on;
    bool _flash_red;
    bool _flash_green;
    bool _flash_blue;
    int _flash_duration;
    int _starttime;
};

//	The end wrapping of the #ifndef Include Guard
#endif
