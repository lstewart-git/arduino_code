

// Homework #1, CS 598
// September 17, 2018
// by Lawrence Stewart

// EXTERNAL LIBRARIES
#include <Arduino.h>
#include <avr/sleep.h>

// ////// CLASS DEFINITION ////////

class cs598MathObj {
  // class supplying mathematics methods
    private:
      unsigned long startMillis;
      unsigned long currentMillis;
      unsigned long waitTime;

    public:
      // constructor
      cs598MathObj(unsigned long waitTimeArg)
      {
        waitTime = waitTimeArg;
        startMillis = millis();
        currentMillis = 0;
      }

      int power (int x, int y) {
      // return x raised to the power of y.
      if (y == 0) return 1;
      if (y == 1) return x;
      int tempval = 1;
      for (int i = 1; i <= y; i++){
        tempval = x * tempval;
        }
      return tempval;}

      // code to run once during setup
      void obj_setup (){
        Serial.println("CS598MathObj Setup.");
        }

      // routines to run once every iteration of main loop
      void obj_loop () {
        // powerdown after a delay of waitTime
        currentMillis = millis();
        if (currentMillis - startMillis >= waitTime){
          Serial.println("Going to Sleep ...");
          // delay to allow serial communications
          delay(50);
          sleep_enable();
          set_sleep_mode(SLEEP_MODE_PWR_DOWN);
          sleep_cpu();
          }
        }
};

// GLOBAL VARIABLES SECTION
// INSTANTIATE A MATH OBJECT
cs598MathObj myinst(8000);

// ///////// END CLASS, START SETUP /////////

void setup() {

  // start serial communications
  Serial.begin(9600);

  // perform setup on MathObj
  myinst.obj_setup();

  // RUN TESTS
  Serial.println(myinst.power(3, 2));  // Should be 9
  Serial.println(myinst.power(5, 1));  // Should be 5
  Serial.println(myinst.power(9, 0));  // Should be 1
  Serial.println(myinst.power(2, 14));  // Should be 16384
  Serial.println(myinst.power(0, 4));  // Should be 0
}

// ////////// END SETUP, START MAIN LOOP ///////'

void loop() {
  myinst.obj_loop();
}
