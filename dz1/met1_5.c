#define N 5
#include <stdio.h>

void rev_neg(int* a);

void rev_neg(int* a) 
{
	int *p;
	
	for (int i=0; i<N; i++) 
	{
		if (*(a+i) < 0) {(*(a+i))*=(-1);}
	}
}

int main(void)
{
	int s, *a;
	for (int i=0; i<N; i++) { scanf("%d ", &s); *(a+i) = s;}
	rev_neg(a);
	for (int i=0; i<N; i++) { printf("%d ", *(a+i));}
	return 0;
	
}



