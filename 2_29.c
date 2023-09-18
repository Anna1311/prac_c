#include <stdio.h>
#include <math.h>

int cycle1(int a)
	{
	int b=0, d=a, i=0;
	while (d>0) {
		i++;
		d/=10;
		 }
	b=(a/pow(10, i));
	for (int j=1; j<=i; j++) {
		b=b+(a%10)*pow(10, j);
		a=(int)a/10;
	}
	return b;
}
		
int main(void)
{
	int n, a;
	scanf("%d", &n);
	scanf("%d",&a);
	a=cycle1(a);
	printf("%d\n", a);
	return 0;
}

