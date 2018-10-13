
#include "Arduino.h"

#include "les_rgb_led.h" 


les_rgb_led::les_rgb_led(int sketch_st_time){

    #define RED_PIN 5
    #define GREEN_PIN 4
    #define BLUE_PIN  3

	//	This is where the pinModes are defined for circuit operation.
	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
    _starttime = sketch_st_time;
}

//	For the 'on', 'off' and 'flash' functions, their function return type (void) is
//	specified before the class-function link. They also use the private variables
//	saved in the constructor code.

void les_rgb_led::red_on(){
  digitalWrite(RED_PIN, HIGH);
}

void les_rgb_led::green_on(){
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
}

void les_rgb_led::blue_on(){
  digitalWrite(BLUE_PIN, HIGH);
}

void les_rgb_led::white_on(){
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
}

void les_rgb_led::yellow_on(){
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
}

void les_rgb_led::purple_on(){
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
}

void les_rgb_led::all_off(){
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
}

void les_rgb_led::flash_white(int delayTime){
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  delay(delayTime);
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  delay(delayTime);
}

void les_rgb_led::flash_red(int delayTime){
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  delay(delayTime);
  digitalWrite(RED_PIN, LOW);
  delay(delayTime);
  }

void les_rgb_led::flash_blue(int delayTime){
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  delay(delayTime);
  digitalWrite(BLUE_PIN, LOW);
  delay(delayTime);
  }

void les_rgb_led::flash_green(int delayTime){
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  delay(delayTime);
  digitalWrite(GREEN_PIN, LOW);
  delay(delayTime);
  }


