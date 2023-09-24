#include <stdio.h>
int n;
void shift_r20(int A[n], int n)
{
	int i,j,x, B[20];
	for (i=n-1; i>=0; i--)
	{
		if (i>=(n-20)) {B[i-n+20]=A[i]; }
		else { A[i+20]=A[i]; }
	}
	for (i=0; i<20; i++)
	{
		A[i]=B[i];
	}
	
}

int main(int argc, char **argv)
{
	int n, i;
	
	scanf("%d", &n);
	int A[n];
	for (i=0; i<n; i++)
	{
		scanf("%d ", &A[i]);
	}
	shift_r20(A, n);
	for (i=0; i<n; i++)
	{
		printf("%d ", A[i]);
	}
	return 0;
}
