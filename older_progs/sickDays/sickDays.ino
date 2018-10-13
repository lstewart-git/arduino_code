/*
  Calculate the probability of employee attendance given a certain amount of sick days
  using Monmte Carlo numerical techniques
 */

void setup() {  
Serial.begin(9600);
randomSeed(analogRead(0));
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
  digitalWrite(13, LOW); 
  


}

void loop() {
  
    // initialize the parameters
int sickDaysYR = 5;   //  average sick days per year per employee
int sickCount = 0;
int days = 10000;     //   length of the model run, in days
int failDay = 0;     //   amount of days with an unacceptable absence rate
int allowedSickies = 1;   // number of absent employees allowed on any day
float perCent = 100;
 
      for (int x = 1; x <= days; x++) {
    sickCount = dayFcn(sickDaysYR);   // call this function once a day to return number of absent employees
    
    if (sickCount > allowedSickies){failDay = failDay + 1;}         //   increment the amount of unacceptable absence days
        }
      
    perCent = (1.0 - (float(failDay) / float (days)));


 
Serial.println(perCent,4);    // print the reliability result to the monitor
delay(10);              // wait for a  10 second
randomSeed(analogRead(0));  //  randomize or else next run yeilds same results
}



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
    
    
  
