// Libraries
#include <aREST.h>

// Create ArduREST instance
aREST rest = aREST();

// Define motor pins
int motorPinPlus = 4;
int motorPinMinus = 5;
int motorPinEnable = 6;

void setup(void)
{  
  // Start Serial & set motor pins
  pinMode(motorPinPlus, OUTPUT);
  pinMode(motorPinMinus, OUTPUT);
  pinMode(motorPinEnable, OUTPUT);
  Serial.begin(115200);
  
  // Give name and ID to device
  rest.set_id("001");
  rest.set_name("motor_control");
}

void loop() {  
 
  // Handle REST calls
  rest.handle(Serial);  
  
}
