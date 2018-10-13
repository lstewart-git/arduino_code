/*
 * myFirstLibrary.h - An introduction to library setup
 * Created by Christian @ Core Electronics on 1/06/18
 * Revision #5 - See readMe 
 */

//	The #ifndef statement checks to see if the myFirstLibrary.h
//	file isn't already defined. This is to stop double declarations
//	of any identifiers within the library. It is paired with a
//	#endif at the bottom of the header and this setup is known as 
//	an 'Include Guard'. 
#ifndef myFirstLibrary_h

//	The #define statement defines this file as the myFirstLibrary
//	Header File so that it can be included within the source file.                                           
#define myFirstLibrary_h

//	The #include of Arduino.h gives this library access to the standard
//	Arduino types and constants (HIGH, digitalWrite, etc.). It's 
//	unneccesary for sketches but required for libraries as they're not
//	.ino (Arduino) files.
#include "Arduino.h"

//	The class is where all the functions for the library are stored,
//	along with all the variables required to make it operate
class myFirstLibrary{

	//	'public:' and 'private:' refer to the security of the functions
	//	and variables listed in that set. Contents that are public can be 
	//	accessed from a sketch for use, however private contents can only be
	//	accessed from within the class itself.
	public:
	
		//	The first item in the class is known as the constructor. It shares the
		//	same name as the class and is used to create an instance of the class.
		//	It has no return type and is only used once per instance.	
		myFirstLibrary(int pinOne, int pinTwo, int pinThree);
		
		//	Below are the functions of the class. They are the functions available
		//	in the library for a user to call.		
		void on();              
		void off();
		void flash(int delayTime);

	private:                  
		
		//	When dealing with private variables, it is common convention to place
		//	an underscore before the variable name to let a user know the variable
		//	is private.		
		int _pinOne, _pinTwo, _pinThree;
};

//	The end wrapping of the #ifndef Include Guard
#endif
