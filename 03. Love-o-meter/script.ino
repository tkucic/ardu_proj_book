const int sensorPin = A0;
const float baselineTemp = 23.0;

void setup(){
    //Start serial monitor
    Serial.begin(9600);
    //Initialize all leds
    for (int i = 2; i < 5; i++){
        pinMode(i, OUTPUT);
        digitalWrite(i, LOW);
    }
}
void loop(){
    int sensorVal = analogRead(sensorPin);
    Serial.print("Sensor value: ");
    Serial.print(sensorVal);

    //Convert the adc reading to voltage
    float voltage = (sensorVal / 1024.0) * 5.0;
    Serial.print(", Volts: ");
    Serial.print(voltage);

    Serial.print(", degrees C: ");
    float temp = (voltage - .5) * 100;
    Serial.print(temp);
    Serial.print("\n"); //Added new line character to break the line in vs code

    //DO something to leds
    if (temp < baselineTemp){
        for (int i = 2; i < 5; i++){
            digitalWrite(i, LOW);
        }
    } else if (temp >= baselineTemp + 2 && temp < baselineTemp + 4){
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
    } else if (temp >= baselineTemp + 4 && temp < baselineTemp + 6){
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
    } else if (temp >= baselineTemp + 6){
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
    }
    delay(1);
}