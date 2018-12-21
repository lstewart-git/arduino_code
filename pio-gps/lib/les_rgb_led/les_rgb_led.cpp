
#include "Arduino.h"
#include "les_rgb_led.h"

les_rgb_led::les_rgb_led(byte unused){

    #define RED_PIN 5
    #define GREEN_PIN 9
    #define BLUE_PIN  3
	FlipTimer = 0;
	FlipFlag = 0;
  flip_color = 0;
}

   void les_rgb_led::Setup()
  {
	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN, OUTPUT);
	pinMode(BLUE_PIN, OUTPUT);
  SetOff();
  last_flip_time = 0;
  }

// MAIN UPDATE METHOD
  void les_rgb_led::Update()
  {
	  if (FlipFlag){    // the led is in flip mode
      if (millis() >= last_flip_time + FlipTimer){
        last_flip_time = millis();  // reset the flip timer
        if (flip_color){
          flip_color = 0;
          SetColor(0, 255, 0);
  		    SetOn();
        } // if flip_color
       else{
         flip_color = 1;
         SetColor(0, 0, 255);
         SetOn();
       } // else
    } // if millis()
	  } // if FlipFlag
  } // UPDATE

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

    void les_rgb_led::SetFlipTime(int flip_interval_ms)
  {
	  FlipTimer =  flip_interval_ms;
  }

     void les_rgb_led::FlipOn()
  {
	  FlipFlag =  1;
  }

      void les_rgb_led::FlipOff()
  {
	  FlipFlag =  0;
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
