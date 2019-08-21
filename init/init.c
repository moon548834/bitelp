#include "vga.h"
int kern_entry()
{
	vga_init();
	screen_clear();
	putline("Hello world!\n bitelp is running!\n");
	return 0;
}
