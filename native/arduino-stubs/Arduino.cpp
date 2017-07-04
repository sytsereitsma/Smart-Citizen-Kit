#include "Arduino.h"

uint8_t TCCR1A;
uint8_t TCCR1B;
uint8_t TIMSK1;
uint8_t TOIE1;
uint8_t SREG;
uint8_t ICR1;
uint8_t TWBR;

int16_t analogRead(int) {
	return 0;
}

void analogReference(Reference) {

}

void delay(uint32_t) {}
void delayMicroseconds(uint32_t) {}

void pinMode (int, PinMode) {

}
void digitalWrite(int, Level level) {}
bool digitalRead(int) {
	return false;
}

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void sei() {}
void cli() {}

uint32_t millis() {return 0;}
