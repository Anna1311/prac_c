#define N 10
#include <stdio.h>

int strings_equal(char* a, char* b);

int strings_equal(char* a, char* b)
{
	int n=0; 
	while (*a && *b)
	{
		while ((*a)==' ') a++;
		while ((*b)==' ') b++;
		if (*a != *b ) {n=1; break;}
		a++; b++;
	}
	return n;
	
}

int main(void)
{
	char *s1="abcdef", *s2="abL cd ef";
	int n;
	n = strings_equal(s1, s2);
	if (n==1) printf("Not equal");
	else printf("Equal");
	return 0;
}
