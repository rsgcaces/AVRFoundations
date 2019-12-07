// PROJECT  :SerialMasterind
// PURPOSE  :Sample client or SerialMastermind library to be used in conjunction with
//          :the ACESSerialMastermind appliance:
//          :http://darcy.rsgc.on.ca/ACES/PCBs/index.html#Mastermind
// COURSE   :ICS3U/ICS4U
// AUTHOR   :C. D'Arcy
// DATE     :2019 12 07
// MCU      :328P
// STATUS   :Version 1.1
// REFERENCE:Serial Input Basics
//          :https://forum.arduino.cc/index.php?topic=288234.0
#include "SerialMastermind.h"
//User enters his secret code on the Serial Input box at RUN time
//Invalid codes result in a random selection by the application
SerialMastermind sm;                    
//Alternate Constructors (overloaded)
//'Developers' enter their code at COMPILE time in a variety of ways
//SerialMastermind sm(200);             //enter any number for a random code
//SerialMastermind sm('R', 'G', 'B');   //user chooses code explicitly
//SerialMastermind sm('B', 'R', 'G');   //user chooses code explicitly
//SerialMastermind sm("RGB");           //user chooses code explicitly

void setup() {
  sm.begin(true);  //true for instructions...
  sm.playGame();
}
void loop() {       // nothing to do; class handles all activity
}
