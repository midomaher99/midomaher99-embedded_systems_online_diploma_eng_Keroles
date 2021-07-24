#include "stdio.h"

void main()
{
	char string[500];
	short length = 0, i ;
/************************************************************************/
	/*taking inputs*/
	printf("Enter a string: ");
	fflush(stdin); fflush(stdout);
	gets(string);
/************************************************************************/
			/*get length*/
	for(i=0; string[i]!=0; i++)
	{
		length +=1;
	}
/************************************************************************/
	printf("length of string = %d", length);
}