#ifndef __SERIAL_H_
#define __SERIAL_H_
#include "Arduino.h"

struct Stream {

	virtual void flush (){}
	virtual void println() {}
	virtual void println(char) {}
	virtual void println(int32_t) {}
	virtual void println(uint32_t) {}
	virtual void println(int64_t) {}
	virtual void println(float) {}
	virtual void println(const __FlashStringHelper*) {}
	virtual void println(const char*) {}
	
	virtual void print(char) {}
	virtual void print(int32_t) {}
	virtual void print(uint32_t) {}
	virtual void print(int64_t) {}
	virtual void print(long int) {}
	virtual void print(float) {}
	virtual void print(const __FlashStringHelper*) {}
	virtual void print(const char*) {}

	template <typename T> 
	void write(const T&) {
	}

	virtual byte read() {
		return 0;
	}

	virtual bool available() {
		return false;
	}
};

class HardwareSerial : public Stream {
public:	
	void begin(uint32_t) {}
};

struct Serial_ : public HardwareSerial {};

extern Serial_ Serial; 
extern HardwareSerial Serial1; 

#endif// __SERIAL_H_
