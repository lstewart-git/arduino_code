
#include "Arduino.h"
#include "cs598hwObj.h"


  // class supplying homework/practice methods


      // CONSTRUCTOR
      cs598hwObj::cs598hwObj(unsigned long waitTimeArg)
      {
        // variables for powerdown at end of execution
        _waitTime = waitTimeArg;
        _startMillis = millis();
        _currentMillis = 0;
      }
    // END CONSTRUCTOR



      void cs598hwObj::obj_setup (){
     // routine to run once during SETUP  ///////////
        Serial.println("cs598hwObj Setup.");
       }  // END SETUP METHOD


      String obj_loop () {
    	// routine to run every iteration of MAIN LOOP ///////////

        String disp_str = "";
        // get the 'random' number from floating pin A2
        _pin_value = analogRead(A2);
        Serial.println("Enter a guess between 1 and 1023.");

        // wait for user input, check timer
        while (_user_guess_str == ""){
          _user_guess_str = Serial.readString();
          _currentMillis = millis(); // check inactivity 'timer'
          // powerdown after a delay of waitTime
          if (_currentMillis - _startMillis >= _waitTime){
             powerdown();
           }
          }

        // input loop broken, process the input:
        // (waiting for user input here is a poor design, I should
        // return control to the main program loop every few milisec so
        // any other objects get a chance to run their _loop methods)
        validate();

        // show output
        if ( _user_guess_str.toInt() >= _pin_value){
          Serial.println("\nHIGHER THAN PIN A2 VALUE");
          digitalWrite(LED_BUILTIN, HIGH);
          disp_str = "HIGH";
        }
        else {
          Serial.println("\nLOWER THAN PIN A2 VALUE");
          digitalWrite(LED_BUILTIN, LOW);
          disp_str = "LOW";
        }
        _user_guess_str = ""; // reset input
        _startMillis = millis(); // reset the inactivity timer
        return disp_str;
        
        }  // END LOOP METHOD



        // Method to power down the microcontroller
        void cs598hwObj::powerdown (){
          Serial.println("Going to Sleep ...");
          // delay to allow final serial communications
          delay(100);
          sleep_enable();
          set_sleep_mode(SLEEP_MODE_PWR_DOWN);
          sleep_cpu();
        } // END POWERDOWN METHOD



        // method to validate user input
        void cs598hwObj::validate (){
          if (_user_guess_str.toInt() < 1){
            Serial.println("Bad Value, Try Again");
            _user_guess_str = ""; // reset input
            return;
            }
          if (_user_guess_str.toInt() >= 1023){
            Serial.println("Bad Value, Try Again");
            _user_guess_str = ""; // reset input
            return;
            }
          if (!_user_guess_str.toInt()){
            Serial.println("Bad Value, Try Again");
            _user_guess_str = ""; // reset input
            return;
            }
        } // END VALIDATE METHOD


