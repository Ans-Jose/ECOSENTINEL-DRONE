#include <Servo.h>
#include <SoftwareSerial.h>

Servo myServo;

const int relay1 = 8;
const int relay2 = 9;
const int irSensor = 7;
const int servoPin = 6;

SoftwareSerial BT(10, 11); 
char btData;

void setup() {
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(irSensor, INPUT);
  
  myServo.attach(servoPin);
  myServo.write(0);

  BT.begin(9600); 
}

void loop() {
  if (BT.available()) {
    btData = BT.read();

    if (btData == 'A') {
      digitalWrite(relay1, HIGH);
      digitalWrite(relay2, LOW);
    } 
    else if (btData == 'B') {
      digitalWrite(relay1, LOW);
      digitalWrite(relay2, HIGH);
    }
  }

   
  if (digitalRead(irSensor) == LOW) {   
    myServo.write(90);   
  } else {
    myServo.write(0);    
  }

  delay(50); 
}
