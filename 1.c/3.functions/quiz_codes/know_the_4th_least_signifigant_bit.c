/*
 * know_the_4th_least_signifigant_bit.c
 *
 *  Created on: Jul 27, 2021
 *      Author: Mohamed Mostafa
 */

#include"stdio.h"

int check_4th_bit(int num);
int main()
{
	int num ;

	printf("Enter an integer number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d", &num);
	printf("The 4th bit is: %d", check_4th_bit(num));
	return 0;
}

int check_4th_bit(int num)
{
	/*all bits will be 1 except the 4th bit remains as it was*/
	int x = num | 0xfffffff7;
	
	
	/*reverse all bits (all bits will be zero except the 4th bit will be toogled)
	 so if it is now 0 ==> it was 1 and x = 0b0000 0000 0000 0000 0000 0000 0000 0000 = 0
 	 	if it is now 1 ==> it was 0 and x = 0b0000 0000 0000 0000 0000 0000 0000 1000 = 8
	 */
	x = ~x;
	switch (x)
	{
		case 8:
			return 0;
			break;
		case 0:
			return 1;
			break;
		default:
			printf("something wrong");
			break;
	}
	return 2;
}

