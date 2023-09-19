

#include <stdio.h>
unsigned rotate_right(unsigned n);
unsigned rotate_left(unsigned n);

unsigned rotate_left(unsigned n)
{
	unsigned p;
	p=n&0x8000000;
	n<<=1;
	n+=p;
	return n;
}

unsigned rotate_right(unsigned n)
{
	unsigned p;
	p=n&1;;
	n>>=1;
	n+=p*(0x8000000);
	return n;
}

	

int main(void)
{
	unsigned int n,x;
	scanf("%u %u", &x, &n);
	for (int i=0;i<n;i++) x=rotate_right(x);
	printf("%d\n", x);
	return 0;
}

