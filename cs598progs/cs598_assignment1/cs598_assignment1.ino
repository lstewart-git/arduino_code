

// Homework #1, CS 598
// September 21, 2018
// by Lawrence Stewart

// EXTERNAL LIBRARIES
#include <Arduino.h>  // for compatibility with eclipse and .cpp
#include <avr/sleep.h>  // library to handle microcontroller power saving functions

// ////// CLASS DEFINITION ////////

class cs598hwObj {
  // class supplying homework/practice methods
    private:
    // variables to time execution and control powerdown:
      unsigned long startMillis;
      unsigned long currentMillis;
      unsigned long waitTime;
      bool inactive_flag = false;
      
      String user_guess_str = "";
      int pin_value;
      

    public:
      // CONSTRUCTOR
      cs598hwObj(unsigned long waitTimeArg)
      {
        // variables for powerdown at end of execution
        waitTime = waitTimeArg;
        startMillis = millis();
        currentMillis = 0;
      }
    // END CONSTRUCTOR

    
       // routine to run once during SETUP  ///////////
      void obj_setup (){
        Serial.println("cs598hwObj Setup.");
       }  // END SETUP METHOD

      // routine to run every iteration of MAIN LOOP ///////////
      void obj_loop () {
        // get the 'random' number from floating pin A2
        pin_value = analogRead(A2);
        
        Serial.println("Enter a guess between 1 and 1024.");
        // wait for user input, check timer
        while (user_guess_str == ""){
          user_guess_str = Serial.readString();
          currentMillis = millis(); // check inactivity 'timer'
          // powerdown after a delay of waitTime
          if (currentMillis - startMillis >= waitTime){
             powerdown();
           }
          }
        // input loop broken, process the input:
        validate();
        Serial.println(user_guess_str);
        if ( user_guess_str.toInt() >= pin_value){
          Serial.println("HIGH GUESS");
          Serial.println(pin_value);
        }
        else {
          Serial.println("LOW GUESS");
          Serial.println(pin_value);
        }
        user_guess_str = ""; // reset input
        startMillis = millis(); // reset the inactivity timer
        

        }  // END LOOP METHOD
        
        // Method to power down the microcontroller
        void powerdown (){
          Serial.println("Going to Sleep ...");
          // delay to allow final serial communications
          delay(100);
          sleep_enable();
          set_sleep_mode(SLEEP_MODE_PWR_DOWN);
          sleep_cpu();
        } // END POWERDOWN METHOD

        // method to validate user input
        void validate (){
          if (user_guess_str.toInt() < 1){
            Serial.println("Bad Value, Try Again");
            user_guess_str = ""; // reset input
            return;
            }
          if (user_guess_str.toInt() >= 1023){
            Serial.println("Bad Value, Try Again");
            user_guess_str = ""; // reset input
            return;
            }
          if (!user_guess_str.toInt()){
            Serial.println("Bad Value, Try Again");
            user_guess_str = ""; // reset input
            return;
            }
        } // END VALIDATE METHOD
}; 
// END CLASS cs598hwObj ////////////////


// GLOBAL VARIABLES
// instantiate a homework object
cs598hwObj myinst(15000);

// ///////// START SETUP /////////

void setup() {

  // start serial communications
  Serial.begin(9600);

  // perform setup on cs598hwObj
  myinst.obj_setup();

}

// ////////// END SETUP, START MAIN LOOP ///////'

void loop() {
  myinst.obj_loop();
}

// END PROGRAM
