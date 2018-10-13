

void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(A1));
Serial.begin(9600);
Serial.setTimeout(250);

}

void loop() {
  Serial.println("Pease enter a number for die side ");
  String mydie = "";
  
  while (mydie.equals("")) {
    mydie = Serial.readString();
  }
  
  int myrange = mydie.toInt();
  if (myrange <= 0){
    Serial.println("Screw You, Try Again");
  }
  else{
Serial.println(random(1, myrange + 1));
  }
delay(1000);

}


  
