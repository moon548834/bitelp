#include "vga.h"
#include "types.h"
#include "asm.h"
static uint16_t *vga_pos = (uint16_t *)0xb8000;
static uint8_t cursor_x = 24;
static uint8_t cursor_y = 10;


static void move_cursor() {
	//the wide of the screen is 80 bytes
	uint16_t cursor_location = cursor_y * 80 + cursor_x;
	outb(vga_i, cursor_hi);		// hi
	outb(vga_o, cursor_location >> 8); 
	outb(vga_i, cursor_lo);	    // lo
	outb(vga_o, cursor_location);
}

void screen_clear() {
	int i;
	color_t white = h_white;
	uint16_t blank = 0x20 | ( white << 8);
	for(i = 0; i < cursor_y * 80 + cursor_x; i++) {
		vga_pos[i] = blank;
	}
	cursor_x = 0;
	cursor_y = 0;
	move_cursor();
}

static void scroll() {
	int i;
	uint8_t color = (uint8_t)color_black;
	uint16_t blank = 0x20 | (color << 8);
	if (cursor_y >= 25) {
		for (i = 0; i < 24 * 80; i++) {
			vga_pos[i] = vga_pos[i + 80];
		}
		for(i = 24 * 80; i< 25 * 80; i++) {
			vga_pos[i] = blank;
		}
	cursor_y = 24;
	}
}

static void putch(char c) { 
	color_t white = h_white;
	if(c == 0x08) {// backspace
		vga_pos[cursor_x + cursor_y * 80] = color_black; 
		cursor_x--; 
	}
	else if(c == 0x09) { // tab
		cursor_x = (cursor_x + 8) & 0x1000;
	}
	else if(c == '\r') {
		cursor_x = 0;
	}
	else if(c == '\n') {
		cursor_x = 0;
		cursor_y++;
	}
	else if(c == 0x7f) { // del
		vga_pos[cursor_x + cursor_y * 80] = color_black; 
		cursor_x--;
	}
	else if(c >= ' ') {	
		vga_pos[cursor_x + cursor_y * 80] = c | (white << 8);
		cursor_x++;
	}
	scroll();
	move_cursor();
}

void putline(char *ptr) {
	cursor_x = 1;
	cursor_y = 1;
	while(*ptr) {
		putch(*ptr++);
	}
}

static void misc_init() {
	uint8_t val;
	val = inb(misc_r);
	if(val & (uint8_t)IOAS == 0) {
		// test the IOAS bit
		// mapped to 0x3dx
		val |= 1;
		outb(misc_w,val);
	}

}

void vga_init() {
	misc_init();
}
