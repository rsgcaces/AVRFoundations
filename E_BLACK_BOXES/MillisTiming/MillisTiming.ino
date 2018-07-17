// PROJECT  :Blink Sketch (Periodic Timing Alternative) 
// PURPOSE  :To demonstrate the technique of monitoring elapsed time
// AUTHOR   :C. D'Arcy
// DATE     :2018 07 01
// STATUS   :Working
// REFERENCE:https://forum.arduino.cc/index.php?topic=503368.0
#define DURATION 500    //High/Low       
#define PIN 1<<PB5      //pin 13
uint64_t lastCount;     //most recent timestamp in ms
void setup() {
  DDRB = PIN;           //pinMode(13,OUTPUT);
  PORTB |= PIN;         //digitalWrite(13, HIGH);
  lastCount = millis(); //obtain the number of ms since the current program started 
}
void loop() {
    if (millis()-lastCount>=DURATION){ // has the current interval elapsed?
      PORTB ^= PIN;                    //toggle the state of pin 13 (XOR)                    
      lastCount = millis();            //reset for next interval
    }
}
