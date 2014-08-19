// Define motor pins
int motorPinPlus = 4;
int motorPinMinus = 5;
int motorPinEnable = 6;

void setup()
{
   pinMode(motorPinPlus, OUTPUT);
   pinMode(motorPinMinus, OUTPUT);
   pinMode(motorPinEnable, OUTPUT);
   Serial.begin(9600);
}

void loop()
{
  
   // Define speed
   int motor_speed;

   // Accelerate forward
   for (motor_speed = 0; motor_speed < 250; motor_speed++)
   {
      setMotor(true, motor_speed);
      delay(10);
   }
}

// Function to control the motor
void setMotor(boolean forward, int motor_speed){
   digitalWrite(motorPinPlus, forward);
   digitalWrite(motorPinMinus, !forward);
   analogWrite(motorPinEnable, motor_speed);
}
