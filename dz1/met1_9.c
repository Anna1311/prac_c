#include <stdio.h>


int len_str(char *str) 
{
	int len;
	char *p=str;
	while (*p) p++;
	len = p-str;
	return len;
}

void new_str(char s[], char t[])
{
	int j1=0, j2=0, j=0, ls=len_str(s);
	char s1[80], s2[80];
	
	
	for (int i=0; i<ls; i++) 
	{
		if ((s[i] >= '0') && (s[i] <= '9')) 
		{ s1[j1]=s[i]; 
			j1++; }
		else {s2[j2]=s[i]; j2++;}	
	}
	 for (int i=0; i<len_str(s1); i++) 
	 {
		 t[j]=s1[i];
		 j++;
	 }
	 
	 for (int i=0; i<len_str(s2); i++) 
	 {
		 t[j]=s2[i];
		 j++;
	 }
	
	
}


int main()
{
	char X[80];
	char Y[80];
	char s[100];
	fgets(X, 80, stdin);
	new_str(X, Y);
	printf("%s\n", Y);

	return 0;
}

