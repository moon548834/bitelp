#include "vga.h"
#include "string.h"
#include "test.h"

int test();

int kern_entry()
{
	vga_init();	
	screen_clear();
	putline("Hello world!\nbitelp is running!\n");	
	test();
	return 0;
}

int test() {
	int res;
	res = string_test();
	res = printk_test();
	return res;
}
