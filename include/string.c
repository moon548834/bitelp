#include "string.h"

inline void *memcpy(void *dest, const void *src, uint32_t len) {
	char *tmp = dest;
	const char *s = src;
	while(len--) 
		*tmp++ = *s++;
	return dest;
}

inline void memset(void *src, uint8_t val, uint32_t len) {	
	char *tmp = src;
	while(len--) {
		*tmp++ = val;
	}
}

inline char *strcpy(char *dest, const char *src) {
	char *tmp = dest;
	while((*dest++ = *src++) != '\0')
		/*nothing*/ ;
	return tmp;
}

inline int strlen(const char *str) {
	int len = 0;
	while(*str++) 
		len++;
	return len;
}

inline int strcmp(const char *str1, const char *str2) {
	int res = 0;
	char c1,c2;
	while(1) {
		c1 = *str1++;
		c2 = *str2++;
		if(c1 != c2) 
			return c1 < c2 ? -1 : 1;
		if(!c1) //e.g. str1 = '\0' str2 = '\0'
			break;
	}
	return 0;
}





















