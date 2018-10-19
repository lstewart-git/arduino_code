
#include "Arduino.h"

#include "les_scanner.h"


les_scanner::les_scanner(int debounce, int modes){

    #define  DATA_PIN = 11;
    #define  CLOCK_PIN = 12;
    #define  LATCH_PIN = 13;
	debounce_millis = debounce;
    num_modes = modes;
}

  void les_scanner::Setup()
  {
	pinMode(DATA_PIN, OUTPUT);
    pinMode(CLOCK_PIN, OUTPUT);
    pinMode(LATCH_PIN, OUTPUT);
  }


  void les_scanner::Update()
  {
    // check to see if it's time to change internal state
  unsigned long currentMillis = millis();

	// check that debounce timer fm last press expired
	if (currentMillis > last_press_time + debounce_millis){


		}
   }
