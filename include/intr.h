#ifndef _INTR_H
#define _INTR_H

#include "types.h"

typedef struct pt_trs_t {
	uint32_t ds;
	uint32_t edi;
	uint32_t esi;
	uint32_t ebp;
    uint32_t esp;
    uint32_t ebx;
    uint32_t edx;
    uint32_t ecx;
    uint32_t eax;
    uint32_t int_no;    // interrupt number
    uint32_t err_code;  
    uint32_t eip;       // processor automatically save 
    uint32_t cs;        
    uint32_t eflags;
    uint32_t useresp;
    uint32_t ss;
} pt_regs;
// ?
typedef void (*interrupt_handler_t)(pt_regs*);


