
#include "Arduino.h"

#include "les_Autopilot.h"


les_Autopilot::les_Autopilot(int parameter) 
{
mode = parameter;
}

void les_Autopilot::Setup()
{
mode = 0;
}


void les_Autopilot::Update()
{
mode = 0;
}
