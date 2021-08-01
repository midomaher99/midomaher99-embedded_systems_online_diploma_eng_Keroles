/*
 * prime_between_interval.c
 *
 *  Created on: Aug 1, 2021
 *      Author: Mohamed Mostafa
 */
#include <stdio.h>
void take_interval_boundaries(int* start, int* end);
int prime(int num);
int main()
{
	int i,interval_start, interval_end;

	take_interval_boundaries(&interval_start, &interval_end);

	for(i = interval_start; i<= interval_end; i++)
	{
		if(prime(i) == 1)
			printf("%d ",i);
	}
	return 0;
}
void take_interval_boundaries(int* start, int* end)
{
	printf("Enter interval boundaries(start end): ");
	fflush(stdin);	fflush(stdout);
	scanf("%d%d",start,end);
}
int prime(int num){
	int i, prime =1;

	for(i = num-1; i>=2;i--)
	{
		if(num == 0 || num == 1 ||num == 2)
			break;

		else if(num%i == 0)
		{
			prime = 0;
			break;
		}
	}

	return prime;
}
