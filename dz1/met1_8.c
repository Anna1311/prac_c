#include <stdio.h>
int compare( char *X,  char *Y);
char* strstr_( char* X,  char* Y);

int compare( char *X,  char *Y)
{
	while (*X && *Y)
	{
		if (*X != *Y) {
			return 0; }
		X++;
		Y++; }
	return (*Y == '\0');
}


 char* strstr_( char* X,  char* Y)
{
	while (*X != '\0')
	{
		if ((*X == *Y) && compare(X, Y)) { return X; }
		X++;
	}
	return NULL;
}


int main()
{
	char *X = "Abc def gh abc def";
	char *Y = "def";

	printf("%s\n", strstr_(X, Y));

	return 0;
}
