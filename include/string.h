#ifndef STRING_H
#define STRING_H

#include "types.h"

void *memcpy(void *dest, const void *src, uint32_t len);
void memset(void *dest, uint8_t val, uint32_t len);

char *strcpy(char *dest, const char *src);
int strlen(const char *src);
int strcmp(const char *str1, const char *str2);
//char *strcat(void *dest, const void *src);


#endif
