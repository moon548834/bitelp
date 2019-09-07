#include "test.h"

int string_test()
{
	char *s1 = "apple";
	char *s2 = "banana";
	if(strcmp(s1,s2) == -1) putline("string test is done!\n");
	return 1;
}

int printk_test()
{
	char s[10] = "abcd";
	printk("s[0] is :%c s[1] is :%c \n",s[0],s[1]);
	printk("s[0] ascii is :%d\n",s[0]);
	printk("s is %s\n",s);
	return 1;
}



