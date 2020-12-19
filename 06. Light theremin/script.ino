int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;
void setup(){
    //Start serial monitor
    Serial.begin(9600);

    //Calibration of the sensor
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);
    while (millis() < 5000) {
        sensorValue = analogRead(A0);
        if (sensorValue > sensorHigh){
            sensorHigh = sensorValue;
        }
        if (sensorValue < sensorLow){
            sensorLow = sensorValue;
        }
    }
    //When the led goes off, calibration is done
    digitalWrite(ledPin, LOW);
}
void loop(){
    sensorValue = analogRead(A0);
    int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

    tone(8, pitch, 20);
    delay(10);
    
}