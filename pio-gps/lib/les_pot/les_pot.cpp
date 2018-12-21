
#include "Arduino.h"

#include "les_pot.h"
#define POT_PIN 0

les_pot::les_pot(int crapval)
{
  pot_value = crapval;
}

  void les_pot::Setup()
  {
    pot_value = 0;
  }


  void les_pot::Update()
  {
    pot_value = analogRead(POT_PIN);
   }
