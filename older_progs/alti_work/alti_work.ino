#include <Wire.h>
#include <BMP085.h>


// Connect VCC of the BMP085 sensor to 3.3V (NOT 5.0V!)
// Connect GND to Ground
// Connect SCL to i2c clock - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 5
// Connect SDA to i2c data - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 4
// EOC is not used, it signifies an end of conversion
// XCLR is a reset pin, also not used here

BMP085 bmp;
float max_alt = 0;
float min_alt = 50000;
float cur_alt = 0;
float cur_delta = 0;
float max_delta = 0;
  
void setup() {
  pinMode(2, OUTPUT);   // Blue Pin
  pinMode(3, OUTPUT);   // Red Pin
  pinMode(5, OUTPUT);   // Blue Pin
  Serial.begin(9600);
  bmp.begin();  
}
  
void loop() {
    digitalWrite(5, LOW);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    check_alt();
    calc_deltas();
    print_data();
    delay(1000);
}

void print_data(){
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal
    Serial.print("Altitude = ");
    Serial.print(cur_alt);
    Serial.println(" meters");
    
    Serial.print("Max Altitude = ");
    Serial.println(max_alt);

    Serial.print("Min Altitude = ");
    Serial.println(min_alt);
    
    Serial.print("Delta = ");
    Serial.println(cur_delta);
    
    Serial.print("Max Delta = ");
    Serial.println(max_delta);
    
    Serial.println();
}

void check_alt(){
  cur_alt = bmp.readAltitude(101325);
  if (cur_alt > max_alt){
    digitalWrite(2, HIGH);
    max_alt = cur_alt;
  }
    if (cur_alt < min_alt){
    digitalWrite(3, HIGH);
    min_alt = cur_alt;
  }
}

void calc_deltas(){
  cur_delta = abs(cur_alt - max_alt);
  if (cur_delta > max_delta) max_delta = cur_delta;

  
}
