#ifndef INCLUDE_COMMON_H
#define INCLUDE_COMMON_H
#include "types.h"

inline void outb(uint8_t port,uint8_t value) {
	asm volatile("outb %0,%1" 
				: 
				:"a"(value),"dN"(port));
}

inline uint8_t inb(uint8_t port) {
	uint8_t value;
	asm volatile("inb %1,%0"
				:"=a"(value)
				:"dN"(port));
	return value;
}

inline uint16_t inw(uint8_t port) {
	uint16_t value;
	asm volatile("inw %1,%0 "
				:"=a"(value)
				:"dN"(port));
}
