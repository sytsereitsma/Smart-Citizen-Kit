#ifndef __WIRE_H_
#define __WIRE_H_

#include "Arduino.h"

struct WireImpl {
	void begin() {}

	uint8_t read() {return 0;}
	void write(uint8_t) {}

	void requestFrom(uint8_t, uint8_t) {};

    void beginTransmission(uint8_t) {}
    void endTransmission() {}

    bool available() {return false;}
};

extern WireImpl Wire;

#endif //__WIRE_H_