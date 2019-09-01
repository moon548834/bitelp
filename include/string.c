#include "string.h"

inline void *memcpy(void *dest, const void *src, uint32_t len) {
	
	char *tmp = dest;
	const char *s = src;
	while(len--) 
		*dest++ = *src++;
	return dest;
}
