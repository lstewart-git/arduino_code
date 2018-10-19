
#include "Arduino.h"

#include "les_scanner.h"


les_scanner::les_scanner(int cycle_time){

    #define  DATA_PIN = 11;
    #define  CLOCK_PIN = 12;
    #define  LATCH_PIN = 13;
    // time in ms between led 'movement'
	  cycle_time = cycle_time;
}

  void les_scanner::Setup()
  {
	   pinMode(DATA_PIN, OUTPUT);
     pinMode(CLOCK_PIN, OUTPUT);
     pinMode(LATCH_PIN, OUTPUT);
     last_update = 0;
     current_position = 0;
     array_argument = B10000000;
  }


  void les_scanner::Update()
  {
    // check to see if it's time to change internal state
  unsigned long currentMillis = millis();

	// check that debounce timer fm last press expired
	if (currentMillis > last_update + cycle_time){
      last_update = currentMillis;
        shiftDisplay(array_argument);
        array_argument = array_argument >> 1;
        current_position++;
        if (current_position >= 8){
          array_argument = B10000000;
          current_position = 0;
        }// END IF

		}
   }

   void les_scanner::shiftDisplay(byte data) {
     digitalWrite(latch_pin, LOW);
     shiftOut(data_pin, clock_pin, LSBFIRST, data);
     digitalWrite(latch_pin, HIGH);
   }
