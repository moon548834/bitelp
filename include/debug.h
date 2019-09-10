#ifndef _DEBUG_H
#define _DEBUG_H

#include "vargs.h"
#include "types.h"
#include "string.h"
#include "vga.h"

#define assert(x) \
	do { \
		if (!x) { \
			printk("Assertion failed: %s file %s, line %d\n", \ 
			#x,__FILE__,__LINE__); \
		} \
	} while (0);

void printk(const char *format, ...);

void init_debug();

void panic(const char *msg);

void print_cur_status();


#endif
