// PROJECT  :SerialMasterind
// PURPOSE  :Sample client or SerialMastermind libray to be used in conjunction with
//          :the ACESSerialMastermind appliance:
//          :http://darcy.rsgc.on.ca/ACES/PCBs/index.html#Mastermind
// COURSE   :ICS3U/ICS4U
// AUTHOR   :C. D'Arcy
// DATE     :2019 11 29
// MCU      :328P
// STATUS   :In Development...
// REFERENCE:Serial Input Basics
//          :https://forum.arduino.cc/index.php?topic=288234.0

#include "SerialMastermind.h"
//Constructors (overloaded)
//SerialMastermind sm;                  //software random chooses code
//SerialMastermind sm(200);             //user chooses code randomly
SerialMastermind sm('B', 'R', 'R'); //user choose code explicitly
//SerialMastermind sm('G', 'G', 'G'); //user choose code explicitly
//SerialMastermind sm("BRR"); //user choose code explicitly

void setup() {
  sm.begin(false);  //true for instructions...
  sm.playGame();
}

void loop() {
}
