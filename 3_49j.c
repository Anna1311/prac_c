#include <stdio.h>
#include <string.h>
int main(void)
{ 
	char str[80];
	int i,ch=0;
	printf("Enter: ");
	fgets(str, sizeof(str), stdin);
	if (strchr(str, '.')) {
		for (i=0;str[i]!='.'; i++) {
			if ((str[i]>='0') && (str[i]<='9')) 
			{
				if (str[i+1]>='0' && str[i+1]<='9')
				{
					if (str[i]<str[i+1]) {ch=1;}
					else { if (ch==1) ch=0; 
						else printf("%c", str[i]);}
				}
				else {
					if (ch==0) printf("%c",str[i]); 
					else ch=0;
					}
			}
			else { printf("%c",str[i]); ch=0; }
		}
	}
	
	return 0;
}


