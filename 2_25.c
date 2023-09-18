#include <stdio.h>

int main(void)
{
	char a,b,c,d;
	unsigned int n=1;
	scanf("%c %c %c %c", &a, &b, &c, &d);
	printf("%c\n", c);
	n=((((a<<8) | b) << 8 | c )<< 8)| d;
	printf("%d\n", n);
	
	return 0;
}

