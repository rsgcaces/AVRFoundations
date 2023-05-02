// PROJECT  :Stepper28BYJ48
// PURPOSE  :Support for demonstration to ICS3U class
// COURSE   :ICS3U
// AUTHOR   :C. D'Arcy
// DATE     :2020 04 28. Confirmed: 2023 05 02.
// MCU      :328P (Nano)
// MOTOR    :MOT-28BYJ-48  (32 teeth, 11.25 degrees between teeth)
// STATUS   :Working
// REFERENCE:https://www.youtube.com/watch?v=B86nqDRskVU
// REFERENCE:https://www.instructables.com/id/BYJ48-Stepper-Motor/
//#include <Stepper.h>        //This libary is OK but (can be) problematic for beginners
#define IN1 8                 //BLUE
#define IN2 9                 //PINK
#define IN3 10                //YELLOW
#define IN4 11                //ORANGE
//Provide separate 5V supply for motor and time control and motor grounds together
#define WAVESTEPS 32*64       //2048
#define FULLSTEPS 32*64       //2048
#define HALFSTEPS 64*64       //4096
#define STEPS     HALFSTEPS   //commit to one of the three above...  
#define TIMEOUT   1000        //control pacing
//for the software-inclined ACES, consider improved code design between barriers
//------------------------------------------------------------------------------
struct drive {
  uint16_t increments;
  uint8_t sequence[8];
  uint8_t steps;
};
drive waveStepping  = {WAVESTEPS, {1, 2, 4, 8, 0, 0, 0, 0}, 4}; //complete
drive fullStepping = {FULLSTEPS, {3, 6, 12, 9, 0, 0, 0, 0}, 4}; //complete
drive halfStepping = {HALFSTEPS, {1, 3, 2, 6, 4, 12, 8, 9}, 8}; //complete
//------------------------------------------------------------------------------
int8_t step;                      //drive steps 0-8 (allow for negative)
boolean clockwise = true;         //direction
uint32_t previousMicros;          //helps with pacing
uint32_t currentMicros;           //ditto
uint16_t stepsRemaining = STEPS;  //countdown of steps for full rotation

void setup() {
  pinMode(IN1, OUTPUT);           //set drive pins for output
  pinMode(IN2, OUTPUT);           //
  pinMode(IN3, OUTPUT);           //
  pinMode(IN4, OUTPUT);           //
  previousMicros = micros();      //timestamp the start
}
void loop() {
  //loop through a full rotor rotation at a controlled pace...
  while (stepsRemaining > 0) {
    takeStep();
    delayMicroseconds(TIMEOUT);
    stepsRemaining--;
  }
  delay(TIMEOUT);           //pause before changing direction
  clockwise = !clockwise;   //change direction
  stepsRemaining = STEPS;   //reset the total number of steps for this drive option
}

//single step through the firing sequence for the currect drive option...
//Note1: This is hardcoded for half-stepping...for demonstration purposes
//Note2: A HIGH to the ULN2003 pulls the coil end low.    
void takeStep() {
  switch (step) {
    case 0:
      digitalWrite(IN1, HIGH);     //BLUE
      digitalWrite(IN2, LOW);    //PINK
      digitalWrite(IN3, LOW);    //YELLOW
      digitalWrite(IN4, LOW);    //ORANGE
      break;
    case 1:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
    case 2:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
    case 3:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    case 4:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      break;
    case 5:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      break;
    case 6:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
    case 7:
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      break;
    default:
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      break;
  }
  nextStep();
}

void nextStep() {
  step = clockwise ? step + 1 : step - 1;
  if (step > 7)
    step = 0;
  else if (step < 0)
    step = 7;
}
