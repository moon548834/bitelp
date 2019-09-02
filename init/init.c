#include "vga.h"
#include "string.h"

void string_test();

int kern_entry()
{
	vga_init();
	
	
	screen_clear();
	putline("Hello world!\nbitelp is running!\n");	
	string_test();
	return 0;
}

void string_test() {
	char *s1 = "apple";
	char *s2 = "banana";
	if(strcmp(s1,s2) == -1) putline("string test is done!\n");
}
