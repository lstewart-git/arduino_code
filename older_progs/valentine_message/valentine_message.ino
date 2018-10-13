#define OLED_DC 11
#define OLED_CS 12
#define OLED_CLK 10
#define OLED_MOSI 9
#define OLED_RESET 13

#include "SSD1306.h"
#include <Wire.h>
#include <BMP085.h>


SSD1306 oled(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
BMP085 bmp;

int count = 1;
int charValue = 1;

void setup()   {                
  Serial.begin(9600);
  bmp.begin(); 
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);  
  // If you want to provide external 7-9V VCC, uncomment next line and comment the one after
  //oled.ssd1306_init(SSD1306_EXTERNALVCC);
  
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  oled.ssd1306_init(SSD1306_SWITCHCAPVCC);

  // init done

  oled.clear();
  



  
  
  
}

void loop()                     
{
 count ++;
 charValue ++;
 char character[2] = {3, '\0'};
 int row = random(5);
 int xposition = random(21);
 
///////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

if (count % 2 > 0){
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
}

if (count % 2 == 0){
  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
}

  oled.drawstring(0, 0, "Julie Rocks !!!"); 


  
  oled.drawstring(0, 2, "Arduino Loves Julie"); 

 
    
 
 
 oled.drawstring((5* xposition) ,row, character); 
  
     
  oled.display();
  delay(100);
  if (count % 50 == 0){oled.clear();}
   }
 

    
  
