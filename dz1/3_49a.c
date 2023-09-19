#include <stdio.h>
#include <string.h>
int main(void)
{ 
	char str[80];
	int i;
	printf("Enter: ");
	fgets(str, sizeof(str), stdin);
	if (strchr(str, '.')) {
		for (i=0;str[i]!='.'; i++) {
			if (str[i]=='?')
				printf("%c", '!');
			else 
				printf("%c", str[i]);
		}
	}
	
	return 0;
}

