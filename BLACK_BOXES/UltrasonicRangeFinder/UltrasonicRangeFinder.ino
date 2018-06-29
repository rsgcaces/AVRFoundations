// Program    :Ultrasonic Range Finder
// Purpose    :Explore the HC-SR04 URF
// Author     :C. D'Arcy (adapted for RSGC ACES from various sources)
// Date       :2018 06 29
// Status     :Working
// Reference  :https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/
// define the Trig and Echo pins of the HC-SR04 Ultrasonic Sensor
// using suitable quick connect pins...ground pin beside pin 13
uint8_t powerPin = 11;          //unit draws only 15 mA
uint8_t trigPin = 12;           //
uint8_t echoPin = 13;           //
uint16_t distance;              //distance in cm
const float multiplier = 0.017; //sound in air: 29 cm/s (precalculate 1/29/2 for efficiency)
char buff[40];                  //output purposes
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);     //declare the trigPin as output
  pinMode(echoPin, INPUT);      //declare the echoPin as input (optional)
  pinMode(powerPin, OUTPUT);    //declare the powerPin as output
  digitalWrite(powerPin, HIGH); //only draws 15 mA, so OK
}
void loop() {
  distance = calculateDistance(); //call function for calculating the distance measured by the Ultrasonic sensor for each degree
  sprintf(buff, "Distance: %d cm", distance);
  Serial.println(buff);
}
// function for acquiring and converting distance using the HC-SR04 Ultrasonic sensor
uint16_t calculateDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 uS
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH) * multiplier;
}

