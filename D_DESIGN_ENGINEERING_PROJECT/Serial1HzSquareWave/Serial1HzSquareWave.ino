// PROJECT  :Serial1HzSquareWave
// PURPOSE  :Places a sqaure wave in the seril stream to be picked up by a listener (Processing)
// DEVICE   :Arduino
// AUTHOR   :C. D'Arcy
// DATE     :2019 01 15
// uC       :328p
// COURSE   :ICS3U
// STATUS   :Working
// NOTES    :Execute this code, then launch the listener: Processing Example>Serial>SimpleRead
#define DURATION 1000
void setup() {
  Serial.begin(9600);            //Start serial communication at 9600 bps
}

void loop() {
  Serial.write(1);               //Place ASCII 1 in the hardware serial stream
  delay(DURATION);               //Wait...
  Serial.write(0);               //Place ASCII 0 in the hardware serial stream
  delay(DURATION);               //Wait...
}

