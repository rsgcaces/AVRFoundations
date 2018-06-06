// PURPOSE  :Highlight the issue of switch bounce 
// AUTHOR   :C. D'Arcy
// DATE     :2018 06 06
// uC       :328
// STATUS   :Working
// REFERENCE: http://www.arduino.cc/en/Tutorial/DigitalReadSerial
uint8_t pushButton = 2;       //monitor state of swith on this pin
uint8_t buttonState;          //holds current reading of switch state
uint8_t lastButtonState;      //preserve the previous state for later comparison
uint8_t changeCount = 0;      //track the total # of switch changes
#define CHANGE_LIMIT 10       //maximum allowable # of state changes
char buff[60];                //serial output buffer (array)
void setup() {
  Serial.begin(9600);
  pinMode(pushButton, INPUT);             //(optional) declare pushbutton's pin an input
  buttonState = digitalRead(pushButton);  //obtain default state
  lastButtonState = buttonState;          //preserve it
  Serial.println(buttonState);            //dispaly initial start state
}
void loop() {
  while ( buttonState == lastButtonState) //poll the pin continuously...
    buttonState = digitalRead(pushButton);//...looking for a state change

  Serial.println(buttonState);            //display the state of the button
  lastButtonState = buttonState;          //back this state up for next comparison
  changeCount++;                          //record one more state change
  if (changeCount == CHANGE_LIMIT) {      //have we reached maximum # of state changes?
    sprintf(buff, "Limit of %-2d state changes reached.%n", CHANGE_LIMIT);
    Serial.println(buff);                 //display summary message
    while (true);                         //pause, indefinitely
  }
}
