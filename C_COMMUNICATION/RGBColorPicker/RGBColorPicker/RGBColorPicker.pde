/**
 * RGB Color Picker 
 * Provides a graphic interface in which to manipulate Arduino functionality
 * over the Serial port
 */

import processing.serial.*;

Serial myPort;  // Create object from Serial class
color red = color(255,0,0);
color green = color(0,255,0);
color blue = color(0,0,255);

void setup() 
{
  size(400, 373);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  background(255);
  stroke(0);
  fill(red);
  ellipse(100,100,200,200);
  fill(green);
  ellipse(300,100,200,200);
  fill(blue);
  ellipse(200,273,200,200);
}

void draw() {
if (mouseOverRed())
  myPort.write('R');
  else if (mouseOverGreen())
  myPort.write('G');
  else if (mouseOverBlue())
  myPort.write('B');
  else myPort.write('0');
}

boolean mouseOverRed() { // Test if mouse is within the red circle
  return pow(mouseX-100,2)+pow(mouseY-100,2) < 10000;
}

boolean mouseOverGreen() { // Test if mouse is within the green circle
  return pow(mouseX-300,2)+pow(mouseY-100,2) < 10000;
}
boolean mouseOverBlue() { // Test if mouse is within the blue circle
  return pow(mouseX-200,2)+pow(mouseY-273,2) < 10000;
}
