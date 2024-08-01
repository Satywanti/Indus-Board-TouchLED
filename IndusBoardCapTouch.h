#ifndef INDUSBOARDCAPTOUCH_H
#define INDUSBOARDCAPTOUCH_H

#include<Arduino.h>

class IndusBoardCapTouch {
public:
    IndusBoardCapTouch(int pin, int ledPin);
    void begin();
    int readCapacitance();
    bool touch();
    void controlLED();
private:
    int _pin;
    int _ledPin;
    const int touchThreshold = 20000;
};

#endif
