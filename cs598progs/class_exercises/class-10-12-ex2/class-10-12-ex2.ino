#include <les_rgb_led.h>
#include <les_button.h>

//Variables
les_rgb_led myLED(100,100);
// les_button myButton(200);
int r = 0;
int g = 0;
int b = 0;
int color_array [3] [3] = {
  {255, 0, 0},
  {0, 255, 0},
  {0, 0, 255}
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
    myLED.SetColor(r, g, b);
    myLED.SetOn();

    r = r +1;
    g = r -70 ;
    b = r - 140;

    if (r > 255 ) r = 0;
    if (r < 0 ) r = 0;
    if ( g > 255 ) g = 0;
    if ( g < 0 ) g = 0;
    if (b > 255) b = 0;
    if (b < 0) b = 0;
    delay(50);

  }
  
 
