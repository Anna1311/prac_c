#include <stdio.h>

int main(void)
{
	unsigned int x, n, p, y, h=0xFFFFFFFF;
	scanf("%d %d %d %d", &x, &n, &p, &y);
	y>>=(32-n);
	y<<=(32-n-p);
	y=~y;
	x=x&y;
	printf("%u\n", y);
	printf("%u\n", x);
	
	return 0;
}

