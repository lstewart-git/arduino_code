/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 #include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
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
    myservo.attach(12);  // attaches the servo on pin 9 to the servo object 
}

void loop() {
 
  int potValue = analogRead(A3);
  int luxValue = analogRead(A2);
    
  if (potValue < 500) (scanFunction(cntr));
  if (potValue >= 500) (backscanFunction(cntr));
    
delay(luxValue);              // wait for a second
 
Serial.println(cntr, luxValue);  
}

void scanFunction (int place) {
    if (cntr > 11){cntr = 2; };
    for (int x = 2; x < 12; x++) {
    digitalWrite(x, LOW);
  }
  digitalWrite(cntr, HIGH);
    myservo.write((cntr * 10) + 25);
    cntr = cntr +1;
    
}

void backscanFunction (int place) {
    if (cntr < 2){cntr = 10; };
    for (int x = 2; x < 12; x++) {
    digitalWrite(x, LOW);
  }
  digitalWrite(cntr, HIGH);
    cntr = cntr -1;
}  
  
