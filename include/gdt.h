#ifndef _GDT_H
#define _GDT_H

#include "types.h"

/*
-----------------------------------------------------------
    Segment Descriptor structure

    Base   G   D/B L   AVL seg limit P	 DPL	S	Type  Base
	31:24  23  22  21  20  19:16     15  14:13  12  11:8  7:0  

	Base Address Segment Limit
	31:16		 15:0

note: GDT is one of the most important Segment Descriptors.
-----------------------------------------------------------
*/

#define STA_X 0x8 // exeutable segment
#define STA_E 0x4 // expend down(non-executable segments)
#define STA_C 0x4 // conforming code segment (executable only)
#define STA_W 0x2 // writeable (non-executable segments)
#define STA_R 0x2 // readable (executbale segments)
#define STA_A 0x1 // accessed



typedef struct gdt_entry_t {
	uint16_t limit_low;
	uint16_t base_low;
	uint8_t  base_mid;
	uint8_t  access;
	uint8_t  granu;
	uint8_t  base_hi;
	// intel like structure, so seperated the Base into different part
	// but G D/B.. bits have not implemented yet
} __attribute__((packed)) gdt_entry_t;


// GDTR
typedef struct gdt_ptr_t {
	uint16_t limit;
	uint32_t base;
} __attribute__((packed)) gdt_ptr_t;

void init_gdt();

extern void gdt_flush(uint32_t); //assembly

#endif
