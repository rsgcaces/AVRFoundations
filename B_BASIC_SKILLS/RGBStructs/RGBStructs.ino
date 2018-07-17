// Project  :RGBStructs
// Purpose  :Introducing Struct data type to ACES
// Author   :C. D'Arcy
// Date     :2018 06 24
// Status   :Working
// Reference:https://playground.arduino.cc/Code/Struct
/* Alternative definition syntax
  typedef struct {
  uint8_t redPin;
  uint8_t gndPin;
  uint8_t greenPin;
  uint8_t bluePin;
  } RGB1;*/
struct RGB {        //definition of a composite data structure
  uint8_t redPin;   //the pin number of the red LED lead
  uint8_t gndPin;   //the common cathode pin
  uint8_t greenPin; //green
  uint8_t bluePin;  //blue
};
RGB led = {3, 4, 5, 6};//create a single instance of an RGB struct
void setup() {
  pinMode(led.redPin, OUTPUT);
  pinMode(led.gndPin, OUTPUT);
  pinMode(led.greenPin, OUTPUT);
  pinMode(led.bluePin, OUTPUT);
  digitalWrite(led.gndPin, LOW);
}
void loop() {
  analogWrite(led.redPin, random(256));   //start with an initial presentation
  analogWrite(led.greenPin, random(256));
  analogWrite(led.bluePin, random(256));
  delay(100);
 
}
