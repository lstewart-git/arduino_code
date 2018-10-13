/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
long randNumber1;
long randNumber2;
int cntr;
int cntdw;

void setup() {  
Serial.begin(9600);  
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
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
  cntr = 2;  
  cntdw = 10;
}

void loop() {
 
  int potValue = analogRead(A2);
  
  if (cntr > 10){cntr = 2; } 
  if (cntdw < 2){cntdw = 10; } 
  
 potValue = potValue - 120;
  if (potValue < 10) (potValue = 10);
  
digitalWrite(cntr, HIGH);   // set the LED on
digitalWrite(cntdw, HIGH);   // set the LED on  
  
delay(potValue);              // wait for a second
     
digitalWrite(cntr, LOW);   // set the LED off
digitalWrite(cntdw, LOW);   // set the LED off

Serial.println(potValue);  
 cntr = cntr + 1;
 cntdw = cntdw -1;
  

}
