#ifndef __EEPROM_H_
#define __EEPROM_H_
#include <cstdint>

struct EEPROMImpl {
	uint8_t read(uint16_t) {return 0;}
	void write(uint16_t, uint8_t) {}
};

extern EEPROMImpl EEPROM;

#endif //__EEPROM_H_