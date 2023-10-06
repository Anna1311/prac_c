#include <stdio.h>

int main(void) 
{ 
	FILE *f, *f2; 
	f= fopen("text1", "r+"); 
	f2 = fopen("esc1", "w");  
	int ch1, ch2, ch3, ch4, ch5;
	if(f == NULL) 
		printf("ERROR\n"); 
		
	
	while(feof(f)==0) 
	{ 
		ch1=fgetc(f);
		if((char)ch1=='e')
		{
			ch2=fgetc(f);
			if((char)ch2=='n')
			{
				ch3=fgetc(f);
				if((char)ch3=='d')
				{
					fputc('}', f2);
				}
				else
				{
					fputc(ch1, f2);
					fputc(ch2, f2);
					fseek(f, -1,SEEK_CUR);
				}
			}
			else
			{
				fputc(ch1, f2);
				fseek(f, -1,SEEK_CUR);
			}
		}
		else
		{
			
		
		if((char)ch1=='b')
		{
			ch2=fgetc(f);
			if((char)ch2=='e')
			{
				ch3=fgetc(f);
				if((char)ch3=='g')
				{
					ch4=fgetc(f);
					if((char)ch4=='i')
					{
						ch5=fgetc(f);
						if((char)ch5=='n')
						{
							fputc('{', f2);
						}
						else
						{	
							fputc(ch1, f2);
							fputc(ch2, f2);
							fputc(ch3, f2);
							fputc(ch4, f2);
							fseek(f, -1,SEEK_CUR);
						}
					}
					else
					{
						fputc(ch1, f2);
						fputc(ch2, f2);
						fputc(ch3, f2);
						fseek(f, -1,SEEK_CUR);
					}
				}
				else
				{
					fputc(ch1, f2);
					fputc(ch2, f2);
					fseek(f, -1,SEEK_CUR);
				}
			}
			else
			{
				fputc(ch1, f2);
				fseek(f, -1,SEEK_CUR);
			}
		}
		else
		{
			fputc(ch1, f2);
		}
	}
					
	}
	//fputc(z, f2);
	//printf("%c \n", z);
		
	//} 
	fclose(f2);
	fclose(f); 
	return 0; 
}
