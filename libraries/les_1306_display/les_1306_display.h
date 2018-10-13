/*
les rgb led driver
 */


#ifndef les_1306_display_h

                                           
#define les_1306_display_h


#include "Arduino.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


class les_1306_display : public Adafruit_SSD1306 {

	public:
	
	
		les_1306_display(int8_t RST = -1);
        void displaySetup();
		


	private:    
        int _myvar; 
        int8_t _RST;            
	
};

//	The end wrapping of the #ifndef Include Guard
#endif
