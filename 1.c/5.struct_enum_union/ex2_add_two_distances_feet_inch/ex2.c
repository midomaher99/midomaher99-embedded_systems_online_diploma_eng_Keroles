/*
 * add_two_distances_in_feet_inch.c
 *
 *  Created on: Aug 4, 2021
 *      Author: moham
 */
#include<stdio.h>
struct Sdistance
{
	int feet;
	float inch;
};
void take_distance(struct Sdistance* distance);
void add_distances(struct Sdistance* distance1,struct Sdistance* distance2,struct Sdistance* sum);
int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	struct Sdistance distance1, distance2,sum;
	printf("Enter 1st distance:\n");

	take_distance(&distance1);
	printf("Enter 2nd distance:\n");

	take_distance(&distance2);

	add_distances(&distance1, &distance2, &sum);

	printf("Sum of distance=%d'%.1f\"",sum.feet, sum.inch);

	return 0;
}
void take_distance(struct Sdistance* distance)
{
	printf("Enter Feet: ");
	scanf("%d",&distance->feet);
	printf("Enter inches: ");
	scanf("%f",&distance->inch);
}
void add_distances(struct Sdistance* distance1,struct Sdistance* distance2,struct Sdistance* sum)
{
	int sum_inch = distance1->inch + distance2->inch ; /*Explicit casting to take integer part only to check if inches exceed 1 foot*/
	sum->feet = distance1->feet + distance2->feet + sum_inch/12; /*last term is the number of feet in sum of inches*/
	sum->inch = distance1->inch + distance2->inch - sum_inch +sum_inch%12;/*last two terms is to exclude feet and remain fraction*/
}
