#include "gdt.h"
#include "string.h"

#define GDT_LENGTH 5

gdt_entry_t gdt_entries[GDT_LENGTH];

gdt_ptr_t gdt_ptr;

static void gdt_set_gate(uint32_t num, uint32_t base, uint32_t limit,
uint8_t access, uint8_t granu);

void init_gdt()
{
	gdt_ptr.limit = sizeof(gdt_entry_t) * GDT_LENGTH - 1;
	gdt_ptr.base = (uint32_t)&gdt_entries;
	
	gdt_set_gate(0, 0, 0, 0, 0);
	// for system the gdt is 0b00 (most privileged), while for user the gdt is 0b11
	gdt_set_gate(1, 0, 0xffffffff, 0x90 | STA_X | STA_R, 0xcf); // code
	gdt_set_gate(2, 0, 0xffffffff, 0x90 | STA_W, 0xcf); // data
	gdt_set_gate(3, 0, 0xffffffff, 0xf0 | STA_X | STA_R, 0xcf); // user code
	gdt_set_gate(4, 0, 0xffffffff, 0xf0 | STA_W, 0xcf);
}

static void gdt_set_gate(uint32_t num, uint32_t base, uint32_t limit,
uint8_t access, uint8_t granu)
{
	gdt_entries[num].base_low = base & 0xffff;
	gdt_entries[num].base_mid = (base >> 16) & 0xff;
	gdt_entries[num].base_hi = (base >> 24) & 0xff;
//limit ??
	gdt_entries[num].limit_low = (limit & 0xffff);
	gdt_entries[num].granu = (limit >> 16) & 0x0f;

	gdt_entries[num].granu |= granu & 0xf0; 
	gdt_entries[num].access = access;	
}
