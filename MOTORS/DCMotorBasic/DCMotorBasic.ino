// PROJECT  :DC Motor: User control
// PURPOSE  :Demonstrates interactive control over motor speed and direction
// AUTHOR   :C. D'Arcy
// DATE     :2018 07 03
// uC       :328
// STATUS   :Working
// REFERENCE:http://mail.rsgc.on.ca/~cdarcy/Datasheets/sn754410.pdf

uint8_t directionPin = 8;                 //slide switch control over forward/reverse
uint8_t motorPin1 = 10;                   //one motor lead
uint8_t motorPin2 = 11;                   //the other motor lead
uint8_t currentDirection = HIGH;          //let's assume forward
uint8_t newDirection = currentDirection;  //back it up to recognize changes
void setup() {
  pinMode(motorPin1, OUTPUT);             //motors lead pins
  pinMode(motorPin2, OUTPUT);             //data direction delcared
}

void loop() {
  newDirection = digitalRead(directionPin); //poll the slide switch
  if (currentDirection != newDirection) {   //check for direction change
    spin(newDirection);                     //start the motor
    currentDirection = newDirection;        //backup for next change
  }
}

void spin(uint8_t dir) {                    //sets the motor spinning in a direction
  digitalWrite(motorPin1, dir);             //whichever state is placed on one lead
  digitalWrite(motorPin2, ~dir);            //the other state is placed on the other lead
}

