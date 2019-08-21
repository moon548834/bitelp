#include "asm.h"

inline void outb(uint16_t port,uint8_t value) {
	asm volatile("outb %0,%1\n\t" 
				: 
				:"a"(value),"dN"(port));
}

inline void outw(uint16_t port, uint16_t value) {
	asm volatile("outw %0,%1\n\t"
				:
				:"a"(value),"dN"(port));
}

inline uint8_t inb(uint16_t port) {
	uint8_t value;
	asm volatile("inb %1,%0\n\t"
				:"=a"(value)
				:"dN"(port));
	return value;
}

inline uint16_t inw(uint16_t port) {
	uint16_t value;
	asm volatile("inw %1,%0\n\t"
				:"=a"(value)
				:"dN"(port));
	return value;
}
