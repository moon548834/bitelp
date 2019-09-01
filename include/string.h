#ifndef STRING_H
#define STRING_H

#include "types.h"

void memcpy(uint8_t *dest, const uint8_t *src, uint32_t len);

void memset(void *dest, uint8_t val, uint32_t len);

int strcmp(const char *str1, const char *str2);

char *strcpy(void *dest, const void *src);

char *strcat(void *dest, const void *src);

int strlen(const char *src);


#endif
