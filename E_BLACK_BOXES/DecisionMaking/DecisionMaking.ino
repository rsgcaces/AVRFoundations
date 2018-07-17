// PROJECT  :LED Sawtooth Ramp
// PURPOSE  :Decision-Making with the if statement
// AUTHOR   :C. D'Arcy
// DATE     :2018 07 01
// uC       :328
// STATUS   :Working
#define DURATION  10
uint8_t pwmPin = 9;         //place anode lead of LED on a PWM Pin for ramping
uint8_t gndPin = 8;         //choose an adjacent pin to ground cathode lead
uint8_t brightness = 0;     //start if OFF position
uint8_t delta = -1;         //ready for the turn
void setup() {
  pinMode(pwmPin, OUTPUT);  //set the direction for the led pins
  pinMode(gndPin, OUTPUT);  //
  digitalWrite(gndPin, LOW);//ground the cathode lead of the LED
}

void loop() {
  analogWrite(pwmPin, brightness);  //set LED brightness level
  delay(DURATION);                  //admire...
  if (brightness == 0 || brightness == 255)   //determine whether to reverse direction
    delta = -delta;                           // if so, do it
  brightness += delta;                        //next brightness level
}
