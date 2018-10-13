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

float alt;
float maxaltitude;
float minaltitude;
float initialalt;
float chuteAltitude = 100.0;
float apogeeDelta = 200.0;
boolean apogee = false;


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
  
  alt = bmp.readAltitude();                    // get the current altitude from the sensor
  initialalt = alt;
  alt = alt - initialalt;
  alt = alt * 3.281;                                  // convert to feet
  maxaltitude = alt;                                // initialize max and min readings to current altitude
  minaltitude = alt;

  
}

void loop()                     
{

float alt = bmp.readAltitude();                    // get the current altitude from the sensor
  alt = alt - initialalt;                              // makes this a differential altimeter
  alt = alt * 3.281;                                  // convert to feet

if (maxaltitude < alt){maxaltitude = alt;}
if (minaltitude > alt){minaltitude = alt;}

int maxalt = int(maxaltitude);                      // reset maxalt value which will be destroyed in calculations
int minalt = int(minaltitude);

int asciiConvert = 48;                               // constant for converting ints to strings

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////START DISPLAY CONVERSION ROUTINE////////////////////////////////////////////////////////////

int input = int(alt);                               // convert the altitude from a float to an int
input = abs(input);                                  // correct for negative values (all because of ascii conversion!!)

  int num1 = (input/1000);                          //  pick off the individual digits of the input
    input = input - (num1 * 1000); 
  int num2 = (input/100);
    input = input - (num2 * 100);
  int num3 = (input/10);
    input = input - (num3 * 10);
  int num4 = input;
  
if (alt >= 0){                                            // Greater than equal zero case,
if (alt > 999){  
num1 = num1 + asciiConvert;}                     // convert the int values to their corresponding ascii values
else {num1 = 32;}

if (alt >99){                                       
num2 = num2 + asciiConvert;}
else {num2 = 32;}

if (alt > 9){
num3 = num3 + asciiConvert;}
else {num3 = 32;}

num4 = num4 + asciiConvert;
}                                                      // end greater than zero case

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
else {                     ///////////////////////////////////////////////////// less than zero case/////////////////////////////////////
if (alt < -99){  
  num1 =45;                    // convert the int values to their corresponding ascii values{num1 = 32;
  num2 = num2 + asciiConvert;
  num3 = num3 + asciiConvert;
  }

if ((alt < -9)&&(alt >= -99)){                                       //  check for negative values, replace leading spaces with minus sign 
  num1 = 32;
  num2 = 45;
  num3 = num3 + asciiConvert;
  }
  
if ( alt < 0 && alt >= - 9){
  num1 = 32;
  num2 = 32;
  num3 = 45;
}

num4 = num4 + asciiConvert;
}



char altitude[5] = {num1, num2, num3,num4, '\0'};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////Could not get a subroutine to work, therefore code duplictaion///////////////



  int maxnum1 = (maxalt/1000);                          //  pick off the individual digits of the input
    maxalt = maxalt - (maxnum1 * 1000);
  int maxnum2 = (maxalt/100);
    maxalt = maxalt - (maxnum2 * 100);
  int maxnum3 = (maxalt/10);
    maxalt = maxalt - (maxnum3 * 10);
  int maxnum4 = maxalt;
  
if (maxaltitude > 999){                                        
maxnum1 = maxnum1 + asciiConvert; }                       // convert the int values to their corresponding ascii values
else {maxnum1 = 32;}                                      // or blanks

if (maxaltitude > 99){
maxnum2 = maxnum2 + asciiConvert;}
else {maxnum2 = 32;}

if (maxaltitude >9){
maxnum3 = maxnum3 + asciiConvert;}
else {maxnum3 = 32;}

maxnum4 = maxnum4 + asciiConvert;

char maxaltitudeDisp[5] = {maxnum1, maxnum2, maxnum3, maxnum4, '\0'};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

       
minalt = abs(minalt);                                    // get rid of negative values for ascii conversion
  int minnum1 = (minalt/1000);                          //  pick off the individual digits of the input
    minalt = minalt - (minnum1 * 1000);
  int minnum2 = (minalt/100);
    minalt = minalt - (minnum2 * 100);
  int minnum3 = (minalt/10);
    minalt = minalt - (minnum3 * 10);
  int minnum4 = minalt;
  
if(minaltitude < -999){                                        //  check for negative values, replace leading spaces with minus sign
  minnum1 = minnum1 + asciiConvert;                        // convert the int values to their corresponding ascii values
  minnum2 = minnum2 + asciiConvert;
  minnum3 = minnum3 + asciiConvert;
}

if(minaltitude < -99 && minaltitude >= -999){
  minnum1 = 45;
  minnum2 = minnum2 + asciiConvert;
  minnum3 = minnum3 + asciiConvert;
}

if(minaltitude < -9 && minaltitude >= -99){
  minnum1 = 32;
  minnum2 = 45;
  minnum3 = minnum3 + asciiConvert;
}

if (minaltitude < 0 && minaltitude >= -9){
  minnum1 = 32;
  minnum2 = 32;
  minnum3 = 45;  
}

minnum4 = minnum4 + asciiConvert;

char minaltitudeDisp[5] = {minnum1, minnum2, minnum3,minnum4, '\0'};
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

if (alt < (maxaltitude - apogeeDelta)){digitalWrite(2, HIGH);                                    //  trigger apogee channel
apogee = true;
}  

if (apogee && (alt < chuteAltitude)){digitalWrite(3, HIGH);}                                  //  trigger main chute channel

  oled.drawstring(0, 0, "Altitude: "); 
  oled.drawstring(60, 0, altitude); 
  oled.drawstring(90, 0, "feet"); 
  
  oled.drawstring(0, 2, "Maximum: "); 
  oled.drawstring(60, 2, maxaltitudeDisp); 
  oled.drawstring(90, 2, "feet"); 
    
  oled.drawstring(0, 3, "Minimum: "); 
  oled.drawstring(60, 3, minaltitudeDisp);   
  oled.drawstring(90, 3, "feet"); 
  
     
  oled.display();
  delay(500);
  oled.clear();
   }
 

    
  




