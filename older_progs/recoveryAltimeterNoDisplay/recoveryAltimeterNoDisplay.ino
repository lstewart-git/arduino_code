//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  ATmega328 microcontroller program  for altimeter based ////////////////////////////////////////
////////////////////////////////////////  dual recovery amateur rocket                          ////////////////////////////////////////
////////////////////////////////////////  by Lawrence E Stewart   February, 2012               ////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////  Header Files  //////////////////////////////////////////////////////////////////////////////
#include <Wire.h>        // communicate with sensor over I2C protocol
#include <BMP085.h>      //  Bosch pressue & temperature sensor driver
#include <EEPROM.h>      //  eeprom memory library access to save values

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////  Global variable declaration  ///////////////////////////////////////////////////////////////
BMP085 bmp;
float alt;
float maxaltitude;
float minaltitude;
float initialalt;
float chuteAltitude = 15.0;
float apogeeDelta = 3.0;
int loopRate = 200;                      //    main loop speed in milliseconds
int apogeeAddress = 10;                  //  eeprom address of max altitude data storage
boolean apogee = false;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////  Initialization code to run once ////////////////////////////////////////////////////////////////
void setup()   {                
  Serial.begin(9600);
  bmp.begin(); 
  pinMode(2, OUTPUT);   
  pinMode(3, OUTPUT);  
  pinMode(13, OUTPUT); 
  digitalWrite(13, HIGH);
  
  alt = getAltitude();                              // get the current altitude from the sensor
  initialalt = alt;
  alt = alt - initialalt;                                  // set to zero initial altitude
  alt = alt * 3.281;                                      // convert to feet
  maxaltitude = alt;                                      // initialize max and min readings to current altitude
  minaltitude = alt;
//////////////////////////////////  SERIAL OUTPUT OF PREVIOUS STORED MAXIMUM VALUE/////////////////////////////////////
  delay(15000);                                          //  delay 15 sec to get serial communications setup on computer
  int recordedApogee = EEPROMReadInt(apogeeAddress);      // read last recorded apogee
  Serial.print(recordedApogee);
  Serial.println();
  digitalWrite(13, LOW);                                  // turn off onboard LED to signal setup function complete
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  MAIN SENSOR LOOP   //////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()                     
{
  float CurrentAltitude = getAltitude();                                          // get the current altitude from the sensor
  CurrentAltitude = CurrentAltitude - initialalt;                                // makes this a differential altimeter
  CurrentAltitude = CurrentAltitude * 3.281;                                    // convert to feet

  if (maxaltitude < CurrentAltitude){maxaltitude = CurrentAltitude;}            // check for and store a new maximum or minimum
  if (minaltitude > CurrentAltitude){minaltitude = CurrentAltitude;}


  if ( (CurrentAltitude<(maxaltitude - apogeeDelta)) && apogee == false){            //  Detect apogee
    digitalWrite(2, HIGH);                                                          //  trigger apogee channel
    apogee = true;
    int IntApogee;                                                                   //  Save apogee reading to EEPROM for later access
    IntApogee = int(maxaltitude);
    EEPROMWriteInt(10, IntApogee);
  }  

  if (apogee && (CurrentAltitude < chuteAltitude)){digitalWrite(3, HIGH);}            //  trigger main chute channel




  Serial.print("Altitude = ");              // debugging and testing code
  Serial.print(maxaltitude - minaltitude);  //////////////////////////////
  Serial.println(" feet");                  /////////////////////////////
  
  delay (loopRate);                        //  CONTROL SSENSOR READ RATE ///
  
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////  EEPROM ACCESS FUNCTIONS  ////////////////////////////////////////////////////////////////////

//This function will write a 2 byte integer to the eeprom at the specified address and address + 1
void EEPROMWriteInt(int p_address, int p_value)
	{
	byte lowByte = ((p_value >> 0) & 0xFF);
	byte highByte = ((p_value >> 8) & 0xFF);

	EEPROM.write(p_address, lowByte);
	EEPROM.write(p_address + 1, highByte);
	}

//This function will read a 2 byte integer from the eeprom at the specified address and address + 1
unsigned int EEPROMReadInt(int p_address)
	{
	byte lowByte = EEPROM.read(p_address);
	byte highByte = EEPROM.read(p_address + 1);

	return ((lowByte << 0) & 0xFF) + ((highByte << 8) & 0xFF00);
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////    SENSOR READ and AVERAGING FUNCTION  /////////////////////////////////////////////////////////////
float getAltitude(){
  int i;
  float bmpResult = 0.0;
  for (i = 0; i < 5; i++){
    bmpResult = bmpResult + bmp.readAltitude();
    delay(5);
  }
  bmpResult = bmpResult / 5.0;
  return bmpResult;
}
    

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////  END PROGRAM  /////////////////////////////////////////////////////////////////////////
    
  




