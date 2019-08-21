#ifndef _VGA_H
#define _VGA_H

#define misc_r 0x3cc
#define misc_w 0x3c2

#define cursor_hi 0x0e
#define cursor_lo 0x0f

#define vga_i 0x3d4
#define vga_o 0x3d5

#define IOAS 1
#define color_black 0b10000000
#define color_white 0b10001111
typedef enum color {
	black = 0,
	blue = 1,
	green = 2,
	cyan = 3,
	red = 4,
	magenta = 5,
	brown = 6,
	white = 7,
	h_white = 15,
} color_t;

void screen_clear();
void putline();
void vga_init();

#endif
