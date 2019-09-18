#ifndef _IDT_H
#define _IDT_H

#include "types.h"

/*
-----------------------------------------------------------
The IDT may contain any of three kinds of gate descriptors:
---- Task-gate
---- Interrupt-gate
---- Trap-gate

Interrupt Gate Structure:

31:16	15  14:13 12:8  7:5 4:0
offset  P   DPL   0D110 000

31:16			  15:0
Segment Selector  offset

-----------------------------------------------------------
*/
void idt_init();

/* __attributed__ ((packed)) means not add padding and it can save memory space in some case
On a 32-bit OS idt_entry_t needs 64bits memory, the same if without packed.
But idt_ptr_t is different, 48bits if packed, 64bits if not.

*/

typedef struct idt_entry_t {
	uint16_t offset_lo;
	uint16_t sel;
	uint8_t always0;
	uint8_t flags;
	uint16_t offset_hi;
} __attribute__ ((packed)) idt_entry_t;


typedef struct idt_ptr_t {
	uint16_t limit;
	uint32_t base;
} __attribute__((packed)) idt_ptr_t;


#endif
