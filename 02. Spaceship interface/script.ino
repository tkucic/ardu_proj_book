int switchState = 0;

void setup(){
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(2, INPUT);
}
void loop(){
    switchState = digitalRead(2);
    if (switchState == LOW){
        //The button is not pressed
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
    } else {
        //Button is pressed
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);

        delay(250); // wait for 1/4 sec

        //toggle leds
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
        delay(250);
    }
}