// Input
int input;

int motorPinPlus = 4;
int motorPinMinus = 5;
int motorPinEnable = 6;

int motorDir;
int motorSpeed;

const int NB_OF_VALUES = 2;
int valuesIndex = 0;
int values[NB_OF_VALUES];

// Setup of the board
void setup() {                
  // Initialize pins
   pinMode(motorPinPlus, OUTPUT);
  pinMode(motorPinMinus, OUTPUT);
  pinMode(motorPinEnable, OUTPUT);

  // Initialize serial port
  Serial.begin(114000);
  
  motorDir = 1;
  motorSpeed = 200;
}

// Main loop
void loop() {
  
  if (Serial.available())
  {
    if (Serial.read() == 'H')
    {
      for(valuesIndex = 0; valuesIndex < NB_OF_VALUES; valuesIndex++)
     {
       values[valuesIndex] = Serial.parseInt();
     }
     
     motorDir = values[0];
     motorSpeed = values[1];
   
    valuesIndex = 0; 
    }
    
    setMotor(motorDir, motorSpeed);
        
  }
  
}
  
// Function to control the motor
void setMotor(int forward, int speed){
    if (forward == 0){
      digitalWrite(motorPinPlus, HIGH);
      digitalWrite(motorPinMinus, LOW);
    }
    else {
      digitalWrite(motorPinPlus, LOW);
      digitalWrite(motorPinMinus, HIGH);
    }
   
    analogWrite(motorPinEnable, speed);
}
