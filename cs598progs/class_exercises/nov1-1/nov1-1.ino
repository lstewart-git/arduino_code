
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <les_rgb_led.h>
#include <les_button.h>
#include <les_pot.h>

//instantiate breadboard objects
les_rgb_led myLED(100);
les_button myButton(350, 4);
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
}
//   ///////////////// MAIN PROGRAM LOOP
void loop()
{
  myPot.Update();
  myButton.Update();
  myLED.Update();
  displayPreFix();
       
 } // ////////////////  END MAIN PROGRAM LOOP


void displayPreFix(){
    les_screen.clearDisplay();
    les_screen.setCursor(10,10);
    les_screen.setTextSize(2);
    float newval = float(myPot.pot_value);
    if (newval < 50.0) newval = 0.0;
    newval = (newval/1023.0) * 5.0;
    int corr_pv = myPot.pot_value;
    if (corr_pv < 80) corr_pv = 0;
    int power = map(corr_pv, 0, 1023, 0, 255);
    if (myButton.state_flag == 1)myLED.SetColor(power, 0, 0);
    if (myButton.state_flag == 2)myLED.SetColor(0, power, 0);
    if (myButton.state_flag == 3)myLED.SetColor(0, 0, power);
    myLED.SetOn();
    les_screen.print(newval);
    les_screen.println("  V");
    les_screen.display();
}

void show_logo(){
  les_screen.clearDisplay();
  les_screen.setTextSize(1);
  les_screen.setTextColor(WHITE);
  les_screen.setCursor(0,0);
  les_screen.println("Hello, Everett!");
  les_screen.display();
}
// END PROGRAM
