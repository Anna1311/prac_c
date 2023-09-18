#include <stdio.h>
#include <string.h>
int main(void)
{ 
	char str[80];
	int i, ch=0;
	printf("Enter: ");
	fgets(str, sizeof(str), stdin);
	if (strchr(str, '.')) {
		for (i=0;str[i]!='.'; i++) {
			if (str[i]=='c' && str[i+1]=='h' && str[i+2]=='i' && str[i+3]=='l' && str[i+4]=='d')
			{
			ch =1;
			printf("children");	
			}
			else {
				if (ch==0) printf("%c", str[i]);
				if (str[i]=='d') ch=0;
				}
			}
	}
	
	return 0;
}
