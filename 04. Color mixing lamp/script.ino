const int greenLEDPin = 9;
const int redLEDPin = 11;
const int blueLEDPin = 10;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int blueValue = 0;
int greenValue = 0;
int redSensorValue = 0;
int blueSensorValue = 0;
int greenSensorValue = 0;

void setup(){
    //Start serial monitor
    Serial.begin(9600);

    pinMode(greenLEDPin, OUTPUT);
    pinMode(blueLEDPin, OUTPUT);
    pinMode(redLEDPin, OUTPUT);
}
void loop(){
    redSensorValue = analogRead(redSensorPin);
    delay(5);
    greenSensorValue = analogRead(greenSensorPin);
    delay(5);
    blueSensorValue = analogRead(blueSensorPin);
    delay(5);

    redValue = redSensorValue / 4;
    greenValue = greenSensorValue / 4;
    blueValue = blueSensorValue / 4;

    Serial.print("Raw Sensor values \t Red: ");
    Serial.print(redSensorValue);
    Serial.print("\t Green: ");
    Serial.print(greenSensorValue);
    Serial.print("\t Blue: ");
    Serial.print(blueSensorValue);
    Serial.print("\n");
    Serial.print("Mapped Sensor values \t Red: ");
    Serial.print(redValue);
    Serial.print("\t Green: ");
    Serial.print(greenValue);
    Serial.print("\t Blue: ");
    Serial.print(blueValue);
    Serial.print("\n");

    analogWrite(redLEDPin, redValue);
    analogWrite(greenLEDPin, greenValue);
    analogWrite(blueLEDPin, blueValue);
    
}