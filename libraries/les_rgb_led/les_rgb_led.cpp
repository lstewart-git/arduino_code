
#include "Arduino.h"
#include "les_rgb_led.h"

les_rgb_led::les_rgb_led(byte unused){

    #define RED_PIN 5
    #define GREEN_PIN 9
    #define BLUE_PIN  3

}

   void les_rgb_led::Setup()
  {
	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
  SetOff();

  }

  void les_rgb_led::Update()
  {
  }

  void les_rgb_led::ShowColor(int colorcode)
  {
    SetColor(built_in_colors[colorcode][0],
            built_in_colors[colorcode][1],
            built_in_colors[colorcode][2]);
    SetOn();
  }

  void les_rgb_led::SetColor(int rp, int gp, int bp)
  {
	  RedPower = rp;
	  GreenPower = gp;
	  BluePower = bp;
  }

  void les_rgb_led::SetOn(){
	  analogWrite(RED_PIN, RedPower);
	  analogWrite(GREEN_PIN, GreenPower);
	  analogWrite(BLUE_PIN, BluePower);
  }

    void les_rgb_led::SetOff(){
	  RedPower = 0;
	  GreenPower = 0;
	  BluePower = 0;
	  analogWrite(RED_PIN, RedPower);
	  analogWrite(GREEN_PIN, GreenPower);
	  analogWrite(BLUE_PIN, BluePower);
  }
