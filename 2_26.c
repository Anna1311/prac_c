#include <stdio.h>

int main(void)
{
	char a,b,c,d;
	unsigned int n=1;
	scanf("%d", &n);
	d=n & 255;
	n=n>>8;
	c=n & 255;
	n=n>>8;
	b=n & 255;
	n=n>>8;
	a=n & 255;
	printf("%c %c %c %c\n", a,b,c,d);
	
	return 0;
}

