#ifndef Morse_h
#define Morse_h

#include "Arduino.h"
#include <avr/sleep.h>

class cs598hwObj {
  // class supplying homework/practice methods



    public:
      // CONSTRUCTOR
      cs598hwObj(unsigned long waitTimeArg);

      void obj_setup ();

      String obj_loop () ;

      void powerdown ();

      void validate ();

    private:
      unsigned long _startMillis;
      unsigned long _currentMillis;
      unsigned long _waitTime;
      String _user_guess_str;
      int _pin_value;

};
// END CLASS cs598hwObj ////////////////

#endif
