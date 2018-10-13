// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(12);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 
    int potValue = analogRead(A3);
                                 // in steps of 1 degree 
    myservo.write(potValue /10 );              // tell servo to go to position in variable 'pos' 
         
  
} 
