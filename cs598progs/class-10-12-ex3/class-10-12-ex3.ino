#include <les_rgb_led.h>
#include <les_button.h>

//Variables
les_rgb_led myLED(100,100);
// les_button myButton(200);
int r = 0;
int g = 0;
int b = 0;
int color_array [6][3] = {
  {255, 0, 0},
  {0, 255, 0},
  {255, 255, 0},
  {0, 125, 255}, 
  {0, 0, 255},
  {30, 0, 255}
};


void setup() {
 myLED.Setup();
// myButton.Setup();
 myLED.SetColor(r, g, b);
 myLED.SetOn();
}

void loop(){
 //   myButton.Update();
    myLED.Update();
    myLED.SetColor(color_array[0] [0], color_array[0] [1], color_array[0] [2]);
   myLED.SetOn();
    delay(1000);
    myLED.SetColor(color_array[1][0], color_array[1][1], color_array[1][2]);
    myLED.SetOn();
    delay(1000);
    myLED.SetColor(color_array[2][0], color_array[2][1], color_array[2][2]);
    myLED.SetOn();
    delay(1000);
    myLED.SetColor(color_array[3][0], color_array[3][1], color_array[3][2]);
    myLED.SetOn();
    delay(1000);
    myLED.SetColor(color_array[4][0], color_array[4][1], color_array[4][2]);
    myLED.SetOn();
    delay(1000);
    myLED.SetColor(color_array[5][0], color_array[5][1], color_array[5][2]);
    myLED.SetOn();
    delay(1000);



  }
  
 
