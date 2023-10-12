#include <stdio.h>
#include <stdlib.h>
struct s {
	int k;
	float *f;
	char *p[2]; 
	};
	
int main(int argc, char **argv)
{
	struct s *ps;
	char str[5] = "abcd";
	ps = (struct s*)malloc(sizeof(struct s));
	(*ps).k = 5;
	ps -> f = (float*) malloc(sizeof(float)); *(ps -> f) = 3.1415; (*ps).p[0] = (char*) malloc(5*sizeof(char));
(*ps).p[1] = (char*) malloc(10*sizeof(char));
(*ps).p[0] = str;
(*ps).p[1] = "abcdefghi";
printf("p[1] %s\n", (*ps).p[0]);

	return 0;
}

