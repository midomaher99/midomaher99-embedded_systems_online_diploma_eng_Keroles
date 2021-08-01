#include "stdio.h"

int main ()
{
	char string [500], character;
	short frequency = 0, i;
/************************************************************************/
        /*taking inputs*/
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(string);
	        
	printf("Enter a charachter to find frequency: ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &character);
/************************************************************************/
	    /*scaning for repetence*/
	for (i = 0; string[i] != 0; i++)
	{
		if (string[i] == character)
			frequency += 1;
	}
/************************************************************************/
	printf("Frequency of %c = %d", character, frequency);
}