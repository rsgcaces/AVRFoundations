// PROJECT  :ServerEchoShiftBar
// PURPOSE  :To demonstrate an Arduino can receive bytes of serial communication from
//          :another Arduino and display the byte on a MorlandSB device
// DEVICE   :2 Arduinos
// AUTHOR   :C. D'Arcy
// DATE     :2019 01 21
// uC       :328
// COURSE   :ICS3U
// STATUS   :Working!
// REFERENCE:Modification of the Example>Communications>PhysicalPixel sketch
// NOTES    :http://www.arduino.cc/en/Tutorial/PhysicalPixel
//          :Client code should be transmitting from SerialClient.ino
//          :Place a Morland SB device in pins 13-9.
#define CLOCK   13
#define POWER   12
#define DATA    11
#define LATCH   10
#define ENABLE  9
uint8_t incomingByte;      // a variable to read incoming serial data into

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  // initialize the MorlandSB device pins as an output:
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(POWER, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  digitalWrite(POWER,HIGH);
  digitalWrite(ENABLE,LOW);
}

void loop() {
  // see if there's incoming serial data:
  if (Serial.available() > 0) {
    // read the oldest byte in the serial buffer:
    incomingByte = Serial.read();
    digitalWrite(LATCH, LOW);
    shiftOut(DATA, CLOCK, MSBFIRST, incomingByte);
    digitalWrite(LATCH, HIGH);
  }
}
