/*
 * q1.c
 *
 *  Created on: Aug 8, 2021
 *      Author: Mohamed Mostafa
 */

#include <stdio.h>
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	int m =29;
	int *ab;

	printf("Address of m: %p\n",&m);
	printf("Value of m: %d\n\n",m);

	ab = &m;
	printf("Address of pointer ab : %p\n",ab);
	printf("Content of pointer ab : %d\n\n", *ab);

	m =34;
	printf("The value of m assigned to 34 now.\n\n");
	printf("Address of pointer ab : %p\n",ab);
	printf("Content of pointer ab : %d\n\n", *ab);

	*ab =7;
	printf("The pointer variable ab is assigned with the value 7 now.\n\n");
	printf("Address of m: %p\n",&m);
	printf("Value of m: %d\n\n",m);
	return 0;
}

