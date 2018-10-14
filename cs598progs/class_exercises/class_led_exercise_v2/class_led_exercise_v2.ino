
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <les_rgb_led.h>

#define OLED_RESET 12
Adafruit_SSD1306 les_screen(OLED_RESET);
long roff = 0;
long ron = 300;

les_rgb_led my_led(ron, roff);
int redcnt = 0;
int greencnt = 0;
int bluecnt = 0;

void setup()
{
  les_screen.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  les_screen.clearDisplay();
  les_screen.setTextSize(1);
  les_screen.setTextColor(WHITE);
  les_screen.setCursor(0,0);
  les_screen.println("Hello, Everett!");
  les_screen.println("cs598 Oct 6 2018");
  les_screen.display();
  delay(2000);
}

void loop()
{

    display_info(254, 0, 0);
    blink_it(254, 0, 0);
    blink_it(254, 0, 0);
    delay(1000);

    display_info(0, 254, 0);
    blink_it(0, 254, 0);
    blink_it(0, 254, 0);
    blink_it(0, 254, 0);
    delay(1000);

    display_info(0, 0, 255);
    blink_it(0, 0, 255);
    blink_it(0, 0, 255);
    blink_it(0, 0, 255);
    blink_it(0, 0, 255);
    delay(1000);


    
    //redcnt = random(254);
    //bluecnt = random(254);
   //greencnt = random(254);
}

void blink_it(int r, int g, int b){
my_led.SetColor(r,g,b);
my_led.SetOn();
delay(500);
my_led.SetColor(0,0,0);
my_led.SetOn();
delay(500);
}

void display_info(int r, int g, int b) {
     les_screen.clearDisplay();
   les_screen.setCursor(0,0);
    les_screen.println("cs598 Oct 4 2018");
    les_screen.print("R ");
    les_screen.println(r);
    les_screen.print("G ");
    les_screen.println(g);
    les_screen.print("B ");
    les_screen.println(b);
    les_screen.display();
}
