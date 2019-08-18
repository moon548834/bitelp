#include "types.h"
int kern_entry()
{
	uint8_t *input = (uint8_t *)0xB8000;
	uint8_t color = (0 << 4) | (15 & 0x0f);
	int i=0;
	while(i++<1000) {
		*input++ = 'H'; *input++ = color;
	}
	return 0;
}
