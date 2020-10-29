// PROJECT  :StringExercises
// PURPOSE  :Gentle Introduction to String-handling functions
// AUTHOR   :C. D'Arcy
// DATE     :2020 10 09
// uC       :*
// STATUS   :Working
// REFERENCE:https://www.arduino.cc/reference/en/language/variables/data-types/stringobject/

// declare a few strings...
char greeting[] = "Hello, ACES!";   //C's primitive string type
String str(greeting);               //Instantiate a String object from a primitive 
String brand = "ACES";              //Instantiate another String object

void setup() {
  Serial.begin(9600);
  while (!Serial);
  //Exploit the 'overloaded' print() and println() functions of the Serial class
  Serial.print("A string as a 0-indexed, null-terminated array of char: ");
  Serial.println(greeting);
  Serial.print("A string as an object of the String Class: ");
  Serial.println(str);

  // diagnostics on a String object 
  uint8_t len = str.length();
  Serial.println("The length of the string is: " + String(len));
  Serial.println("The first character of '" + str + "' is: " + String(str.charAt(0)));
  Serial.println("The last character of '" + str + "' is: " + String(str.charAt(len - 1)));
  
  //locating a string within a string... 
  uint8_t brandPos = str.indexOf(brand);
  if (brandPos)
    Serial.println(brand + " was found at position " + String(brandPos) + " within " + str);
  else
    Serial.println(brand + " is not a substring of " + str);

  // Normalizing the case of letters in a String is often useful 
  // Note this CHANGES the string 
  str.toLowerCase();
  Serial.println("Converted to lowercase: " + str);

  str.toUpperCase();
  Serial.println("Converted to uppercase: " + str);
  
  
  //Use the compareTo function to determine relative rank (for sorting purposes)
  Serial.println("Comparing "+str+" to "+brand+" yields: "+str.compareTo(brand));
  
  //compare Strings for rank (less than, greater than, equal)
  Serial.print("Is "+str+" greater than "+brand+": ");
  Serial.println(str.compareTo(brand)?"Yes":"No");

  Serial.print("Is "+str+" equal to "+brand+": ");
  Serial.println(str.compareTo(brand)==0?"Yes":"No");
  
  Serial.print("Is "+brand+" equal to "+brand+": ");
  Serial.println(brand.compareTo(brand)?"No":"Yes");
  
  Serial.println(str + " disemvoweled becomes " + disemvowel(str));

  //Add statements here to test completed bodoes of stub functions
}

/***************************************************************
 * Eliminates the vowels from the String parameter             *
 * PreCondition: Parameter is a valid String object            *
 * PostCondition: Returns the parameter with its vowels removed*
 ***************************************************************/
String disemvowel(String s) {
  uint8_t pos = 0;              // start indeox at 0
  while (pos < s.length()) {    // examine every character position
    if (isVowel(s.charAt(pos))) // is the character a vowel? 
      s.remove(pos,1);          //    if so, eliminate it
    else pos++;                 //    if no, advance position
  }
  return s;                     // return the edited String (vowels removed)
}

/*****************************************************************
 * Confirms or denies the character parameters status as a vowel *
 * PreCondition: Parameter is a valid character                  *
 * PostCondition: Returns true if the parameter is a vowel       * 
 *                false, otherwise                               *                                               * 
 ****************************************************************/
boolean isVowel(char ch) {
  String vowels = "AaEeIiOoUu";
  return vowels.indexOf(ch) >= 0;
  //or simply, bordering on unreadable, the single statement...
  //return String("AaEeIiOoUu").indexOf(ch)>=0;
}

/*****************************************************************
 * ?                                                             *
 * PreCondition:                                                 *
 * PostCondition:                                                * 
 *****************************************************************/
boolean isPunctuation(char ch) {
  return false;
 }

/*****************************************************************
 * ?                                                             *
 * PreCondition:                                                 *
 * PostCondition:                                                * 
 *****************************************************************/
boolean isDigit(char ch) {
  return false;
 }

/*****************************************************************
 * Returns the sum of ASCII values of all characters in a String *                                      
 * PreCondition: the parameter is a valis String object          *                                                *
 * PostCondition: returns the total of te ASCII values           * 
 *                of all characters in th String                 * 
 *****************************************************************/
uint16_t hashCode(String s){
  return 0;
}

void loop() {}
