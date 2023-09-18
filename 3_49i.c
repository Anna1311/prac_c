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
			if (str[i]=='t' && str[i+1]=='h' && str[i+2]=='e') 
			{
			ch =1;	
			}
			else {
				if (ch==0) printf("%c", str[i]);
				if (str[i]=='e') ch=0;
				}
			}
	}
	
	return 0;
}


