// PROJECT  :LCDAnalogMeter2223
// PURPOSE  :Early ICS3U Introduction to LCD Display of Sensor Data (Potentiometer)
// DEVICE   :Arduino + (Adafruit 1447) LCD Appliance + Potentiometer
// AUTHOR   :C. D'Arcy
// DATE     :2023 02 26
// uC       :328p
// COURSE   :ICS3U
// STATUS   :Working
// REFERENCE:https://www.arduino.cc/en/Reference/LiquidCrystal
// REFERENCE:"Hello, World!" Tutorial: https://www.arduino.cc/en/Tutorial/HelloWorld
// REFERENCE:http://darcy.rsgc.on.ca/ACES/TEI3M/2223/images/LCDAnalogMeter2223.png
#include <LiquidCrystal.h>        //LCD Library...
#define LCD_COLUMNS 16            //Number of columns in Character LCD screen
#define LCD_ROWS    2             //Number of rows on LCD screen
//define a custom character to be used for the display
// REFERENCE:https://www.arduino.cc/en/Reference/LiquidCrystalCreateChar
uint8_t midBlock[8] = {0, 0, 0x1F, 0x1F, 0x1F, 0x1F, 0, 0};
//Pin assignments below are LCD Appliance-compatible
uint8_t EN = 9, RS = 8, D4 = 7, D5 = 6, D6 = 5, D7 = 4;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  Serial.begin(9600);
  lcd.begin(LCD_COLUMNS, LCD_ROWS); //initialize LCD screen
  lcd.clear();                      //erase the LCD screen
  lcd.setCursor(0, 0);              //position display cursor at home
  lcd.print("Adjust your pot");     //provide an instruction on the first line
  lcd.createChar(0, midBlock);      //register custom character definition in HD44780 EEPROM
}

void loop() {
  uint16_t reading = analogRead(A5);                      //obtain sensor (pot) reading
  uint8_t value = map(reading, 0, 1023, 0, LCD_COLUMNS);  //scale it for display
  Serial.print(reading);
  Serial.println("\t" + String(value));
  lcd.setCursor(0, 1);    //position LCD cursor at the start of the second row
  for (uint8_t i = 0; i <= value; i++)
    lcd.write(255);       //http://darcy.rsgc.on.ca/ACES/Datasheets/HD44780.pdf#page=17
  //lcd.write(byte(0));   //or, first custom character (midBlock in this case)
  delay(200);             //admire...
  lcd.setCursor(0, 1);                //prepare to erase the second row
  lcd.print("                    ");  //do it...
}
