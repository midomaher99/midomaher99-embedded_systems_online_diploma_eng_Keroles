#include"stdio.h"
void main()
{
	char string[500], temp;
	short length = 0, i, j;
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
	for(i=0, j = length - 1; i < j; i++, j--)
	{
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;
	}
/************************************************************************/
		printf("%s", string);
}