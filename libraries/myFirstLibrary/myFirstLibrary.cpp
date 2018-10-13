//	.ino (Arduino) files. 
#include "Arduino.h"

//	This will include the Header File so that the Source File has access
//	to the function definitions in the myFirstLibrary library.
#include "myFirstLibrary.h" 

//	This is where the constructor Source Code appears. The '::' indicates that
//	it is part of the myFirstLibrary class and should be used for all constructors
//	and functions that are part of a class.
myFirstLibrary::myFirstLibrary(int pinOne, int pinTwo, int pinThree){

	//	This is where the pinModes are defined for circuit operation.
	pinMode(pinOne, OUTPUT);
	pinMode(pinTwo, OUTPUT);
	pinMode(pinThree, OUTPUT);

	//	The arguments of the constructor are then saved into the private variables.
	_pinOne = pinOne;
	_pinTwo = pinTwo;
	_pinThree = pinThree;
}

//	For the 'on', 'off' and 'flash' functions, their function return type (void) is
//	specified before the class-function link. They also use the private variables
//	saved in the constructor code.

void myFirstLibrary::on(){
  digitalWrite(_pinOne, HIGH);
  digitalWrite(_pinTwo, HIGH);
  digitalWrite(_pinThree, HIGH);
}

void myFirstLibrary::off(){
  digitalWrite(_pinOne, LOW);
  digitalWrite(_pinTwo, LOW);
  digitalWrite(_pinThree, LOW);
}

void myFirstLibrary::flash(int delayTime){
  for(int i = 0; i < 4; i++){
  digitalWrite(_pinOne, HIGH);
  digitalWrite(_pinTwo, HIGH);
  digitalWrite(_pinThree, HIGH);
  delay(delayTime);
  digitalWrite(_pinOne, LOW);
  digitalWrite(_pinTwo, LOW);
  digitalWrite(_pinThree, LOW);
  delay(delayTime);
  }
}
