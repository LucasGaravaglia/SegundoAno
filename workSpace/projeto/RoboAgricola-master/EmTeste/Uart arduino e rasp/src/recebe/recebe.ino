String inputString = "";         
bool stringComplete = false;  

void setup() {
  Serial.begin(9600);
  inputString.reserve(200);
}
void imprimirSerial(){
   if (stringComplete) {
    Serial.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}
void loop() {
 imprimirSerial();
}

void serialEvent() {
  while (Serial.available()) {    
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
