// Project  :StructVariations
// Purpose  :Introducing ACES to C/C++'s struct data type
// Author   :C. D'Arcy
// Date     :2019 11 13
// Status   :Working
// Reference:https://playground.arduino.cc/Code/Struct

//struct definition syntax
struct student {        //definition of a composite data structure
  uint8_t age;
  float mark;
  char house;
};
//define an instance of the student struct
student engineer = {15, 88.6, 'C'};

//Alternative struct definition syntax
typedef struct {
  uint8_t age;
  float mark;
  char house;
} georgian;
//define an instance of the georgian struct
georgian ACE = {16, 91.3, 'Y'};

String heading = "AGE\tMARK\tHOUSE";
void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println(heading);
  //display an instance of the first struct variation...
  Serial.print(engineer.age);
  Serial.print('\t');
  Serial.print(engineer.mark);
  Serial.print('\t');
  switch (engineer.house) {
    case 'C': Serial.print("Canterbury"); break;
    case 'W': Serial.print("Westminster"); break;
    case 'w': Serial.print("Winchester"); break;
    case 'Y': Serial.print("York"); break;
    default : Serial.print("Unknown");
  }
  Serial.println();
  //display an instance of the second struct variation...
  Serial.print(ACE.age);
  Serial.print('\t');
  Serial.print(ACE.mark);
  Serial.print('\t');
  switch (ACE.house) {
    case 'C': Serial.print("Canterbury"); break;
    case 'W': Serial.print("Westminster"); break;
    case 'w': Serial.print("Winchester"); break;
    case 'Y': Serial.print("York"); break;
    default : Serial.print("Unknown");
  }
  Serial.println();

  //Once preferred syntax is elected, use a common function for displaying fields
  displayStruct(engineer);
}
/*
   Function displays the contents of the input parameter, s, to the Serial Monitor
   Precondition: s is a valid student instance
   PostCondition: values of s are displayed on the Serial Monitor
*/
void displayStruct(student s) {
  Serial.print(s.age);
  Serial.print('\t');
  Serial.print(s.mark);
  Serial.print('\t');
  switch (s.house) {
    case 'C': Serial.print("Canterbury"); break;
    case 'W': Serial.print("Westminster"); break;
    case 'w': Serial.print("Winchester"); break;
    case 'Y': Serial.print("York"); break;
    default : Serial.print("Unknown");
  }
  Serial.println();
}

void loop() {
}
