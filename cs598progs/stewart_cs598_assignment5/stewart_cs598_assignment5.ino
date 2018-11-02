
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <les_rgb_led.h>
#include <les_button.h>
#include <les_pot.h>

// program control flow variable
// will be used to call display routine only
// when button state has changed between Update calls
int state_change = 0; 

//instantiate breadboard objects
les_rgb_led myLED(100);
les_button myButton(350, 5);
les_pot myPot(69);

//instantiate an oled_display object
#define OLED_RESET 12
Adafruit_SSD1306 les_screen(OLED_RESET);

void setup()
{
  les_screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  myLED.Setup();
  myButton.Setup();
  myPot.Setup();
  show_logo();
}  //  END SETUP

//   ///////////////// MAIN PROGRAM LOOP
void loop()
{
  myPot.Update();
  myButton.Update();
  myLED.Update();
  if (myButton.state_flag != state_change){
    state_change = myButton.state_flag;
    displayData();
    }
  
 } // ////////////////  END MAIN PROGRAM LOOP


void displayData(){
    les_screen.clearDisplay();
    les_screen.setCursor(10,10);
    les_screen.setTextSize(2);

      if (myButton.state_flag == 1){
      myLED.FlipOff();
      myLED.SetColor(0, 0, 0);
      myLED.SetOn();
      les_screen.println("Off");
    }
    
    if (myButton.state_flag == 2){
      myLED.SetColor(0, 255, 0);
      myLED.SetOn();
      les_screen.println("Green");
    }
    
    if (myButton.state_flag == 3){
      myLED.SetColor(0, 0, 255);
      myLED.SetOn();
      les_screen.println("Blue");
    }
      if (myButton.state_flag == 4){
      myLED.SetColor(0, 0, 0);
      myLED.FlipOn();
      les_screen.println("Alternate");
    }

    les_screen.display();
}

void show_logo(){
  les_screen.clearDisplay();
  les_screen.setTextSize(1);
  les_screen.setTextColor(WHITE);
  les_screen.setCursor(0,0);
  les_screen.println("Lawrence Stewart");
  les_screen.println("CS 598 Assignment #5");
  les_screen.println("November 8, 2018");
  les_screen.display();
}
// END PROGRAM
