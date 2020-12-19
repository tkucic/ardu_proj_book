#include <Servo.h>

Servo myServo;

int const potPin = A0;
int potVal;
int angle;

void setup(){
    //Start serial monitor
    Serial.begin(9600);
    myServo.attach(9);
}
void loop(){
    potVal = analogRead(potPin);
    Serial.print("potVal: ");
    Serial.print(potVal);

    angle = map(potVal, 0, 1023, 0, 179);
    Serial.print(", angle: ");
    Serial.print(angle);
    Serial.print("\n");

    myServo.write(angle);
    delay(15);
    
}