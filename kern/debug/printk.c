#include "debug.h"

static int vsprintf(char *buff, const char *format, va_list args);

void printk(const char *format, ...) 
{
	static char buff[1024];
	va_list args;
	int i;
	va_start(args,format);
	i = vsprintf(buff, format, args);
	va_end(args);
	buff[i] = '\0';
	putline(buff);
}

#define do_div(n,base) ({ \
	int __res;           \
	__asm__("divl %4\n\t" :"=a"(n),"=d"(__res) :"0"(n),"1"(0),"r"(base)); \ 
	__res; })

static char *number(char *str, int num, int base)
{
	const char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char tmp[36];
	int i;
	i = 0;
	if(num == 0) 
		tmp[i++] = '0';
	else {
		while(num != 0) 
			tmp[i++] = digits[do_div(num,base)];
	}
	while (i-- > 0) 
		*str++ =tmp[i];
	return str;
}


static int vsprintf(char *buff, const char *format, va_list args)
{
	char *s;
	char *str;
	int len;
	int i;
	for(str = buff; *format; format++) {
		if(*format != '%') {
			*str++ = *format;
			continue;
		}
    ++format; //skips '%'	
	switch (*format) {
	case 'c':
		*str++ = (uint8_t) va_arg(args,int);
		break;
	case 's':
		s = va_arg(args, char*);
		len = strlen(s);
		for (i = 0; i < len; i++)
			*str++ = *s++;
		break;
	case 'd':
	case 'u':
		str = number(str, va_arg(args, uint32_t), 10);
		break;
	case 'x':
	case 'X':
		str = number(str, va_arg(args, uint32_t), 16);
		break;
	default:
		break;
	}
	}
	*str = '\0';
	return (int)(str - buff);
}
