#include <IndusBoardCapTouch.h>

int pin = 4; // Example pin number
int ledPin = 7;

IndusBoardCapTouch board(pin, ledPin);

void setup() {
    Serial.begin(115200);
    board.begin();
}

void loop() {
    int capacitance = board.readCapacitance();
    bool isTouched = board.touch();

    Serial.print("Capacitance on pin ");
    Serial.print(pin);
    Serial.print(": ");
    Serial.println(capacitance);

    if (isTouched) {
        Serial.println("Touch detected!");
    } else {
        Serial.println("No touch detected.");
    }

    board.controlLED();
    delay(1000);
}
