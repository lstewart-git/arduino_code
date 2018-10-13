#define OLED_DC 11
#define OLED_CS 12
#define OLED_CLK 10
#define OLED_MOSI 9
#define OLED_RESET 13

#include <SSD1306.h>
#include <Wire.h>
#include <BMP085.h>


SSD1306 oled(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
BMP085 bmp;




void setup()   {                
  Serial.begin(9600);
  bmp.begin(); 
  
  // If you want to provide external 7-9V VCC, uncomment next line and comment the one after
  //oled.ssd1306_init(SSD1306_EXTERNALVCC);
  
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  oled.ssd1306_init(SSD1306_SWITCHCAPVCC);

  // init done

  oled.clear();

  
}

void loop()                     
{

float alt = bmp.readAltitude();                    // get the current altitude from the sensor

int asciiConvert = 48;                               // constant for converting ints to strings

int input = int(alt);                               // convert the altitude from a float to an int

  int num1 = (input/1000);                          //  pick off the individual digits of the input
    input = input - (num1 * 1000);
  int num2 = (input/100);
    input = input - (num2 * 100);
  int num3 = (input/10);
    input = input - (num3 * 10);
  int num4 = input;
  
num1 = num1 + asciiConvert;                        // convert the int values to their corresponding ascii values
num2 = num2 + asciiConvert;
num3 = num3 + asciiConvert;
num4 = num4 + asciiConvert;

char altitude[5] = {num1, num2, num3,num4, '\0'};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////Could not get a subroutine to work, therefore code duplictaion///////////////

int maxalt = int(alt);                               // convert the max altitude from a float to an int

  int maxnum1 = (maxalt/1000);                          //  pick off the individual digits of the input
    maxalt = maxalt - (maxnum1 * 1000);
  int maxnum2 = (maxalt/100);
    maxalt = maxalt - (maxnum2 * 100);
  int maxnum3 = (maxalt/10);
    maxalt = maxalt - (maxnum3 * 10);
  int maxnum4 = maxalt;
  
maxnum1 = maxnum1 + asciiConvert;                        // convert the int values to their corresponding ascii values
maxnum2 = maxnum2 + asciiConvert;
maxnum3 = maxnum3 + asciiConvert;
maxnum4 = maxnum4 + asciiConvert;

char maxaltitude[5] = {maxnum1, maxnum2, maxnum3,maxnum4, '\0'};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




  oled.drawstring(0, 0, "Altitude: "); 
  oled.drawstring(60, 0, altitude); 
  oled.drawstring(90, 0, "meters"); 
  
  oled.drawstring(0, 2, "Maximum: "); 
  oled.drawstring(60, 2, maxaltitude); 
  oled.drawstring(90, 2, "meters"); 
    
  oled.drawstring(0, 3, "Minimum: "); 
  
  oled.drawstring(90, 3, "meters"); 
  
     
  oled.display();
  delay(1000);
  oled.clear();
   }
 

    
  




