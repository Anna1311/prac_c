#include <stdio.h>
int n;
void inserts(int A[n], int n)
{
	int i,j,x;
	for (i=0; i<n; i++)
	{
		x=A[i];
		j=i;
		while ((j>0) && (A[j-1]>x)) 
		{
			A[j]=A[j-1];
			j-=1;
		}
		A[j]=x;
	}
}

int main(int argc, char **argv)
{
	int n, i;
	int A[n];
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d ", &A[i]);
	}
	inserts(A, n);
	for (i=0; i<n; i++)
	{
		printf("%d ", A[i]);
	}
	return 0;
}

