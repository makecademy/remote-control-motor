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
      setMotor("0,1," + String(motor_speed));
      delay(10);
   }
}

// Function to control the motor
int setMotor(String command)
{
   digitalWrite(motorPinPlus, command[0]);
   digitalWrite(motorPinMinus, command[2]);
   analogWrite(motorPinEnable, motor_speed);
}
