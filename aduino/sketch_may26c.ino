#include <SoftwareSerial.h>
SoftwareSerial BTSerial(2, 3);
int led = 9;
String my_text="";

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  if(BTSerial.available()){
    char cmd = (char)BTSerial.read();
    if(cmd == '1'){
      digitalWrite(led, HIGH);
    } else if(cmd == '2'){
      digitalWrite(led, LOW);
    }
  }

  if(Serial.available()) BTSerial.write(Serial.read());
  
}

