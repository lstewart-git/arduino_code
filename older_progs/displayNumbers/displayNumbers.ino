#define OLED_DC 11
#define OLED_CS 12
#define OLED_CLK 10
#define OLED_MOSI 9
#define OLED_RESET 13

#include <SSD1306.h>

SSD1306 oled(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);





void setup()   {                
  Serial.begin(9600);
  
  // If you want to provide external 7-9V VCC, uncomment next line and comment the one after
  //oled.ssd1306_init(SSD1306_EXTERNALVCC);
  
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  oled.ssd1306_init(SSD1306_SWITCHCAPVCC);

  // init done

  oled.clear();

  
}

void loop()                     
{

int asciiConvert = 48;
 int input = 1; 

  int num1 = (input/1000);                          //  pick off the individual digits of the input
    input = input - (num1 * 1000);
  int num2 = (input/100);
    input = input - (num2 * 100);
  int num3 = (input/10);
    input = input - (num3 * 10);
  int num4 = input;
  
num1 = num1 + asciiConvert;
num2 = num2 + asciiConvert;
num3 = num3 + asciiConvert;
num4 = num4 + asciiConvert;

char answer[5] = {num1, num2, num3,num4, '\0'};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////




  oled.drawstring(0, 0, "Larry Rocks !!!");  
  oled.drawstring(6, 1, "Julie Rocks !!!");  
    oled.drawstring(11, 2, "Julie Rocks !!!"); 
      oled.drawstring(16, 3, answer); 
     
  oled.display();
  delay(1000);
  oled.clear();
  

for (int i =1; i<=10; i++){
      oled.drawchar(0,0, i+47);
      oled.display();
      delay(100);
      oled.clear();
        }
 }
 

    
  




