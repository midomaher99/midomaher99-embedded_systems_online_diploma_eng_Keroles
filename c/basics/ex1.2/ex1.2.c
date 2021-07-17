#include "stdio.h"
int main()
{
	int x;
	printf ("Enter a integer: ");
	fflush (stdin);
	fflush (stdout);
	scanf ("%d",&x);
	printf ("You entered: %d",x);
	return 0;
}