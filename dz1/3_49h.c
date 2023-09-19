#include <stdio.h>

int main(void)
{
	char str[80];
	int i, ch=0;
	printf("Enter: ");
	fgets(str, sizeof(str), stdin);
	for (i=0; str[i]!='.'; i++) {
		ch=0;
		if (str[i] != '0') printf("%c",str[i]);
		if (str[i]=='0') {
			if ((int)str[i-1] <= 57 && (int)str[i-1] >= 49) printf("%c",str[i]);
			if (str[i+1]=='0') continue;
			if ((int)str[i+1] > 57 || (int)str[i+1] < 49) printf("%c",str[i]);
			}
		}
	
				
	return 0;
}

