/*
 * q2.c
 *
 *  Created on: Aug 8, 2021
 *      Author: Mohamed Mostafa
 */

#include <stdio.h>
int main()
{
	int i;
	char alpha[27]={0}, *ptr;
	for (i=0; i<26;i++)
		alpha[i] = 'A'+i;
	ptr =alpha;
	for (i=0; i<26;i++)
		{
			printf("%c  ",*(ptr++));
		}
	return 0;
}
