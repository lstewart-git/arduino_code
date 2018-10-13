/*

Sick Days, a numerical model for the Arduino microcontroller
by Lawrence Stewart
February, 2012

  Calculate employee dispatch reliability given a certain amount of sick days
  using Monmte Carlo numerical techniques then display the results on an array of 9 LEDs
  this version is for the case 4 pilots, 3 aircraft, 1 pilot on reserve
 */

void setup() {  
Serial.begin(9600);                            // setup serial communications over the USB line
randomSeed(analogRead(0));                     // seed the pseudorandom generator with a floating voltage value

  // initialize the digital pin as an output.
  // LEDs will be used for output:
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);  
  pinMode(4, OUTPUT);   
  pinMode(5, OUTPUT);  
  pinMode(6, OUTPUT);   
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT);   
  pinMode(9, OUTPUT);  
  pinMode(10, OUTPUT);   
  pinMode(11, OUTPUT);  
  pinMode(13, OUTPUT); 
  digitalWrite(13, LOW);   // turn off the onboard LED
  }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////MAIN LOOP////////////////////////////////////////////////////////////////////////////
void loop() {
  
                                                    // initialize the parameters
int sickDaysYR = 10;                                //  average sick days per year per employee
int sickCount = 0;
long days = 10000;                                  //   length of the model run, in days
int failDay = 0;                                    //   amount of days with an unacceptable absence rate
int allowedSickies = 1;                             // number of absent employees allowed on any day
float perCent = 1.0;

 for (long x = 1; x <= days; x++) {
    sickCount = dayFcn(sickDaysYR);                 // call this function once a day to return number of absent employees
        if (sickCount > allowedSickies){failDay = failDay + 1;}      //   increment the amount of unacceptable absence days
 }
      
perCent = (1.0 - (float(failDay) / float (days)));    // calculate the percent of acceptable dispatch days


                                                     // output code, send results to computer vias usb and to LED array
Serial.println(perCent,4);                           // print the reliability result to the monitor

for (int x = 1; x<=3; x++){
cycleDisplay();                                      // flash LED array 3 times to signal an answer is about to be output
delay(270);                                          // wait 
}

LEDoutput(perCent);                                   //  activate LED array with output data

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int dayFcn (int sickDaysYR) {
                                                      //   compute the number of sick employees on a given day using random numbers and the individual
                                                      //   probability of each employee being sick
  int sick = 0;
  long LS = random(1,364);
  long GF = random(1,364);
  long RS = random(1,364);
  long NR = random(1,364);
  
  
    if (LS <=sickDaysYR){sick = sick + 1;}
    if (GF <=sickDaysYR){sick = sick + 1;}
    if (RS <=sickDaysYR){sick = sick + 1;}
    if (NR <=sickDaysYR){sick = sick + 1;}
                                                     //   return the number of sick employees that day
 return sick;
    }
    
    
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void clearDisplay() {                                 //   clear the LED output array
  for(int x = 2; x<=10; x++ ){
      digitalWrite(x, LOW);
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cycleDisplay() {                                 //  flash the LEDs sequentially
  for(int x= 2; x<=10; x++ ){
    digitalWrite(x, HIGH);
    delay(65);
    digitalWrite(x, LOW);
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LEDoutput(float reliable) {                     //   display the answer using the LED array
  reliable = reliable * 10000.0;                      //   format and cast the answer, originally recieved as a decimal less than one
  int ontime = 1300;
  int offtime = 400;
  
  int answer = int(reliable);
  int num1 = (answer/1000);                          //  pick off the individual digits of the answer
    answer = answer - (num1 * 1000);
  int num2 = (answer/100);
    answer = answer - (num2 * 100);
  int num3 = (answer/10);
    answer = answer - (num3 * 10);
  int num4 = answer;
  

                                                       //   display a digit of the answer
digitalWrite(num1+1, HIGH);
delay(ontime);
clearDisplay();
delay(offtime);
  
                                                     //   display a digit of the answer
                                                      
digitalWrite(num2 + 1, HIGH);
delay(ontime);
clearDisplay();
delay(offtime);
  
                                                     //   display a digit of the answer
digitalWrite(num3 + 1, HIGH);
delay(ontime);
clearDisplay();
delay(offtime);
   
                                                     //   display a digit of the answer
digitalWrite(num4 + 1, HIGH);
delay(ontime);
clearDisplay();
delay(offtime);   
 }


