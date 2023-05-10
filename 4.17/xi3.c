#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define DAYS_IN_YEAR(year) ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0 ? 366 : 365)

int main()
{
	int year;
	printf("Please enter a year ");
	scanf("%d",&year);
	printf("This year has %d days\n",DAYS_IN_YEAR(year));
	return 0;
}
