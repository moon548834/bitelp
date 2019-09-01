#include "string.h"

inline void *memcpy(void *dest, const void *src, uint32_t len) {
	char *tmp = dest;
	const char *s = src;
	while(len--) 
		*tmp++ = *src++;
	return dest;
}

inline char *strcpy(char *dest, const char *src) {
	char *tmp = dest;
	while((*dest++ = *src++) != '\0')
		/*nothing*/ ;
	return tmp;
}


inline void *memset(void *src, )























=======
	
	char *tmp = dest;
	const char *s = src;
	while(len--) 
		*dest++ = *src++;
	return dest;
}
>>>>>>> 2061b7a75c7e6bed1b484236f35fb3cf06ccf260
