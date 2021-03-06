// PROJECT  :TMP36 
// PURPOSE  :To demonstrate the versatility of the TMP36 Temperature Sensor 
// AUTHOR   :C. D'Arcy
// DATE     :2018 06 30
// uC       :328
// STATUS   :Working
// REFERENCE:http://mail.rsgc.on.ca/~cdarcy/Datasheets/TMP35_36_37.pdf
// REFERENCE:https://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor
#define DURATION 1000     //delay between readings implies frequency of readings
uint8_t sensorPin = A0;   //use the first analog input pin, why not?
uint16_t rawADC;          //the raw 10-bit ADC reading
float vRef = 5.0;         //define the voltage reference (2.7V <-> 5.0V)
//float vRef = 3.3;       //lowering the voltage reference increases resolution and improve accuracy
float tempC;              //the temperature in degrees Celsius

void setup() {                //one-time prep
  Serial.begin(9600);         //establish the baud rate for communication
  pinMode(sensorPin, INPUT);  //will be reading an analog voltage
//  analogReference(EXTERNAL);  //for voltages other than the DEFAULT 5 VDC 
}

void loop() {
  rawADC = analogRead(sensorPin);     //obtain a reading from he TMP36
  delay(DURATION);                    //pause (includes time for ADC to settle)
                                      //conversion: rawADC > mV > #degC > offset...
  tempC = map(rawADC, 0, 1024, 0, vRef * 1000) / 10.0 - 50.0;
  // Publish results
  Serial.print("raw ADC (0-1023): "+String(rawADC));
  Serial.println("\tCelsius: "+String(tempC));
}
