#include "IndusBoardCapTouch.h"
#include "Arduino.h"


IndusBoardCapTouch::IndusBoardCapTouch(int pin, int ledPin) {
_pin = pin;
_ledPin = ledPin;
}

void IndusBoardCapTouch::begin() {
    pinMode(_pin, INPUT);
    pinMode(_ledPin, OUTPUT);
}

int IndusBoardCapTouch::readCapacitance() {
    return touchRead(_pin);
}

bool IndusBoardCapTouch::touch() {
    int capacitance = readCapacitance();
    return capacitance > touchThreshold;
}

void IndusBoardCapTouch::controlLED() {
    int capacitance = readCapacitance();
    if (capacitance > touchThreshold) {
        digitalWrite(_ledPin, HIGH); // Turn LED on
        Serial.println("LED is ON");
     } else {
        digitalWrite(_ledPin, LOW); // Turn LED off
        Serial.println("LED is OFF");
    }
}
