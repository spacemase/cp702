/******************************************************************  
*
*  Mason Jensen
*  February 28, 2007
*
******************************************************************/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

typedef struct monetary_bills{
	int hundreds;
	int fifties;
	int twenties;
	int tens;
	int fives;
	int ones;
} Bills;

void getAmount(int *figure);
void getDenominations(const int figure, Bills *bills);
void printDenominations(const Bills bills);

void main(void)
{
	int dollar_figure;
	Bills minimum_bills;

	getAmount(&dollar_figure);
	getDenominations(dollar_figure, &minimum_bills);
	printDenominations(minimum_bills);
}

void getAmount(int *figure)
{
	printf("\nPlease enter a dollar amount less than 1,000,000:  ");
	scanf("%d", figure);
}

void getDenominations(const int figure, Bills *bills)
{
	int temp = figure;

	bills->hundreds = temp / 100;
	temp %= 100;
	bills->fifties = temp / 50;
	temp %= 50;
	bills->twenties = temp / 20;
	temp %= 20;
	bills->tens = temp / 10;
	temp %= 10;
	bills->fives = temp / 5;
	temp %= 5;
	bills->ones = temp;
}

void printDenominations(const Bills bills)
{
	printf("\n\n%-10s%10d\n", "$100 - ", bills.hundreds);
	printf("%-10s%10d\n", "$50 - ", bills.fifties);
	printf("%-10s%10d\n", "$20 - ", bills.twenties);
	printf("%-10s%10d\n", "$10 - ", bills.tens);
	printf("%-10s%10d\n", "$5 - ", bills.fives);
	printf("%-10s%10d\n\n", "$1 - ", bills.ones);
}
