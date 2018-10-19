
const int data_pin = 11;
const int clock_pin = 12;
const int latch_pin = 13;



void setup() {
  // put your setup code here, to run once:
 
pinMode(data_pin, OUTPUT);
pinMode(clock_pin, OUTPUT);
pinMode(latch_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte x = B10000000;
    // Turn LEDs on one at a time
  for ( int i = 0; i < 8; i++ ) {
    shiftDisplay(x);
    x = x >> 1;
    delay(40);
  }
  byte z = B00000001;
    for ( int t = 0; t < 8; t++ ) {
    shiftDisplay(z);
 
    z = z << 1;
    delay(40);
  }
}

void shiftDisplay(byte data) {
  digitalWrite(latch_pin, LOW);
  shiftOut(data_pin, clock_pin, LSBFIRST, data);
  digitalWrite(latch_pin, HIGH);
}
