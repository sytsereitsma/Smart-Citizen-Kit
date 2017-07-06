#ifndef __ARDUINO_STUBS_H_
#define __ARDUINO_STUBS_H_

#include <cstdint>
#include <cstdlib>

typedef uint8_t byte;
typedef bool boolean;
typedef uint8_t __FlashStringHelper;

enum Reference : uint8_t {
	INTERNAL,
	EXTERNAL,
	DEFAULT,
};

enum Level : uint8_t {
	LOW,
	HIGH,
};


inline const char* F(const char* s) {
	return s;
}

enum AnalogInput {
	A0,
	A1,
	A2,
	A3,
	A4,
	A5,
	A6,
	A7,
	A8,
};

void analogReference(Reference);
int16_t analogRead(int);

void delay(uint32_t);
void delayMicroseconds(uint32_t);

enum Pin: uint8_t {
	MOSI,
	SCK,
};

enum PinMode : uint8_t {
	INPUT,
	OUTPUT,
};

void pinMode (int, PinMode);
void digitalWrite(int, Level level);
bool digitalRead(int);

long map(long x, long in_min, long in_max, long out_min, long out_max);

inline uint8_t lowByte(uint16_t value) {return value & 0xFF;}
inline uint8_t lowByte(uint32_t value) {return value & 0xFF;}
inline uint8_t lowByte(int32_t value) {return value & 0xFF;}

inline uint8_t highByte(uint16_t value) {return value >> 8;}
inline uint8_t highByte(uint32_t value) {return value >> 24;}

template <typename T>
inline bool bitRead(T value, uint8_t bit) {
	return (value >> bit) != 0; 
}

void sei();
void cli();
uint32_t millis();

#define ISR(x) void x()


extern uint8_t TCCR1A;
extern uint8_t TCCR1B;
extern uint8_t TIMSK1;
extern uint8_t TOIE1;
extern uint8_t SREG;
extern uint8_t ICR1;
extern uint8_t TWBR;

enum Bits {
	CS10,
	CS11,
	CS12,
	WGM13,
};

inline uint8_t _BV(uint8_t value) {
	return 1 << value;
}


enum {
	B00001100 = 12
};

#define strstr_P(s, p) strstr(s, (const char*)p)
#define strlen_P(s) strlen((const char*)s)
#endif // __ARDUINO_STUBS_H_