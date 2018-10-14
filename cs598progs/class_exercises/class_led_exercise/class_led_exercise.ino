
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
   les_screen.clearDisplay();
   les_screen.setCursor(0,0);
    les_screen.println("cs598 Oct 4 2018");
    les_screen.print("R ");
    les_screen.println(redcnt);
    les_screen.print("G ");
    les_screen.println(greencnt);
    les_screen.print("B ");
    les_screen.println(bluecnt);
    
    les_screen.display();
    my_led.SetOn();
    my_led.SetColor(redcnt, greencnt, bluecnt);
    delay(1300);
    redcnt = random(254);
    bluecnt = random(254);
    greencnt = random(254);
}
