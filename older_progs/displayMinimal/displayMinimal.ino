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
  
 int var = 6; 
 int var3 = 9;
 char var2 = char(var+48);
 char var4 = char(var3+48);
  
char myStr[3] = {var2,var4,'\0'} ;
  oled.drawstring(0, 0, "Larry Rocks !!!");  
  oled.drawstring(6, 1, "Julie Rocks !!!");  
    oled.drawstring(11, 2, "Julie Rocks !!!"); 
      oled.drawstring(16, 3, myStr); 
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
 

    
  




