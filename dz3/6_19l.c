#include <stdio.h>
struct data { 
	char *s; 
	int i; 
	struct data *dp; }; 
	
int main(void)
	{ static struct data a[ ] = { 
		{ "abcd", 1, a+1 }, 
		{ "efgh", 2, a+2 },
		{ "ijkl",3, a } };
	struct data *p = a; 
	int i;
	printf("a[0].s=%s p -> s=%s a[2].dp -> s=%s\n", a[0].s, p -> s, a[2].dp -> s);
	for ( i = 0; i < 2; i++ ) printf("--a[i].i=%d ++a[i].s[3]=%c\n",--(a[i].i), a[i].s[3]); printf("++(p->s)=%s\n", ++(p->s) );
	printf("a[(++p) -> i].s=%s\n", a[(++p) -> i].s);
	printf("a[--(p -> dp -> i)].s=%s\n", a[--(p -> dp -> i)].s); 
	return 0;
	}
