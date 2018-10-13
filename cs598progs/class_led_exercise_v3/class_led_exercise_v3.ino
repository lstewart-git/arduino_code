
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
int counter = 0;

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

    display_info(counter);
    if (counter%3==0){
    blink_it(random(254), random(254), random(254));}
    delay(500);
    counter++;
  
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

void display_info(int counter) {
     les_screen.clearDisplay();
   les_screen.setCursor(0,0);
   les_screen.setTextSize(1);
    les_screen.println("cs598 Oct 4 2018");
    les_screen.println("Counter: ");
    les_screen.setTextSize(2);
    les_screen.println(counter);
    les_screen.display();
}
