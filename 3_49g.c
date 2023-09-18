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
			if (str[i]=='*') 
				ch++;
			else { if (str[i-1]=='*')
					{
						if (ch==1) printf("%c", (str[i]));
					for (int i=0; i<(ch/2); i++, printf("%c", '*')) ;
					ch=0;
					}
					printf("%c", (str[i]));
				}
			}
		}
	
	
	return 0;
}


