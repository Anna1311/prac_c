#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 2
#define K 2
int m, n, k, i, j, q;

void func(double a[m][n], double b[n][k], double c[m][k], int m, int n, int k)
{
		 for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
			c[i][j]=0;
			for (int q=0; q<k; q++) {
				c[i][j]+=a[i][q]*b[q][j];
			}
        }
    }
}


int main(void) {
	int m, n, k, i, j, q;
	scanf("%d %d %d", &m, &n, &k);
	double A[m][n], B[n][k], C[m][k];
	
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            A[i][j] = (double)rand()/10000000;
        }
    }
 
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf  ", A[i][j]);
        }
        printf("\n");
    }
     printf("\n");
     
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            B[i][j] = rand()/10000000;
        }
    }
 
    for (i = 0; i < n; i++) {
        for (j = 0; j < k; j++) {
            printf("%lf  ", B[i][j]);  
        }
        printf("\n");
    }
    printf("\n");
   
   func(A, B, C, m, n, k);
    
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            printf("%lf  ", C[i][j]);
        }
        printf("\n");
    }
 
    
     /* for (i = 0; i < m; i++) {
        for (j = 0; j < k; j++) {
            C[i][j] = 0;
            for (q = 0; q < n; q++) {
				C[i][j] += A[i][n]*B[n][j];
			}
			printf(" %lf ", C[i][j]);
        }
        printf("\n");
    } */
 return 0;
}
