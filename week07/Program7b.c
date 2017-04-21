/*****************************************************************************
* Course:       C Intermediate Programming                                   *
*                                                                            *
* Program Name: Assignment7a.c                                               *
*                                                                            *
* Author:       Mason Jensen                                                 *
*                                                                            *
* Date:         March 7, 2007                                                *
*                                                                            *
* Description:                                                               *
*                                                                            *
* The Game of Life – a survival simulation game – was invested by Cambridge  *
* mathematician John H. Conway, and first reported in print by Martin Gardner*
* in the October 1970 issue of Scientific American magazine.  It has become  *
* one of the legendary pastimes for programmers.                             *
*                                                                            *
* The game runs on a square, two-dimensional array, representing a flat      *
* surface that can contain “creatures” or “cells”.  The starting arrangement *
* of “creatures” is either randomly generated or entered by the user.  For   *
* this assignment, allow the user the option of choosing either random       *
* placement, or specifying the occupied cells.                               *
*                                                                            *
* Given the initial array of creatures, the program goes into a loop for a   *
* number of “generations”.  In each generation, creatures are born or die    *
* according to three laws:                                                   *
*                                                                            *
* 1. SURVIVAL – a currently occupied (living) cell survives if it has either *
*    exactly two (2) or three (3) neighbors.  (A neighbor is an immediately  *
*    adjacent array cell with a creature in it.)                             *
* 2. DEATHS – Each occupied (living) cell with four (4) or more neighbors    *
*    dies of overcrowding.  Each occupied (living) cells with one (1) or less*
*    neighbors dies of loneliness.                                           *
* 3. BIRTHS – An empty cell will give birth to a new creature IF, and ONLY IF*
*    it has EXACTLY three (3) neighbors.                                     *
*                                                                            *
* It is important to realize that all the births and deaths occur            *
* simultaneously.  Together they constitute a single generation, or a “move” *
* in the life history.                                                       *
*                                                                            *
******************************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define MAXROW 10
#define MAXCOL 10

void openOutputFile(void);
int menuScreen(void);
void initializeToEmpty(void);
void displayWorld(void);
void copyNextToCurrent(void);
void manualPlacement(void);
void randomPlacement(void);
void simulateLife(void);

int num_generation;
char current[MAXROW + 2][MAXCOL + 2];
char next[MAXROW + 2][MAXCOL + 2];
FILE *outfile;

void main(){
	int code;

	openOutputFile();
	code = menuScreen();

	while (code != 5) {
		switch (code) {
			case 1:
				randomPlacement();
				displayWorld();
				break;
			case 2:
				manualPlacement();
				displayWorld();
				break;
            case 3:
				initializeToEmpty();
				displayWorld();
				break;
			case 4:
				simulateLife();
				copyNextToCurrent();
				displayWorld();
				break;
		}

		printf("\n\nHit any key to continue");
		/*getch();*/
		getchar();

		code = menuScreen();
	}
}

/**************************************
* This function opens the output file *
**************************************/
void openOutputFile ( ) {
	if (( outfile = fopen("lifegame.txt","w")) == NULL) {
        printf("Opening output file failed - lifegame.txt\n");
        exit(1);
	}
}

/*******************************************************************************
* This function displays the menu and allows the user to select 1 to 5 
options *
*******************************************************************************/
int menuScreen() {
	int code, status;

	do {
		printf("\n\n\t\t     MAIN MENU\n");
		printf("\t\t-----------------------------\n");
		printf("\t\t1. Random Placement\n");
		printf("\t\t2. Manual Placement\n");
		printf("\t\t3. Clear Game Board\n");
		printf("\t\t4. Simulate Life\n");
		printf("\t\t5. Quit\n");
		status = scanf("%d", &code);
		while (getchar() != '\n');
	} while (status != 1 || code < 1 || code > 5);

	return code;
}

/********************************************************
* This function initializes the current array to empty. *
/*******************************************************/
void initializeToEmpty() {
	int row, col;

	num_generation = 0;
	for (row = 0; row < MAXROW + 2; row++)
		for (col = 0; col < MAXCOL + 2; col++)
			current[row][col] = '-';
}

/**************************************************************************
* This function displays the world and also indicates when the world ends *
**************************************************************************/
void displayWorld() {
	int row, col, num_living = 0;

	printf("\nGeneration %d:\n", num_generation);
	fprintf(outfile, "Generation %d:\n", num_generation);
	for (row = 1; row < MAXROW + 1; ++row)
	{
		for (col = 1; col < MAXCOL + 1; ++col)
		{
			printf("%2c", current[row][col]);
			fprintf(outfile, "%2c", current[row][col]);
			if (current[row][col] == '*')
				++num_living;
		}
		printf("\n");
		fprintf(outfile, "\n");
	}

	if ((num_living == 0) && (num_generation != 0))
	{
		printf("THE WORLD HAS ENDED\n\n");
		fprintf(outfile, "THE WORLD HAS ENDED\n\n");
	}
	fprintf(outfile, "\n");
}

/**********************************************************************
* This function copies the next generation to the current generation. *
**********************************************************************/
void copyNextToCurrent() {
	int row, col;

	for (row = 1; row < MAXROW + 1; ++row)
		for (col = 1; col < MAXCOL + 1; ++col)
			current[row][col] = next[row][col];
}

/*********************************************************************
* This function allows the user to populate a cell (row and column). *
*********************************************************************/
void manualPlacement() {
	int row = 1, col = 1;

	fprintf(outfile, "< Board edited manually >\n");
	while ((row != 0) && (col != 0))
	{
		printf("Please enter a row and column to populate('0 0' to quit):  ");
		scanf("%d%d", &row, &col);

		current[row][col] = '*';
	}

	fflush(stdin);
}

/********************************************************************
* This function randomly populates the world for a given percentage *
* selected by the user.                                             *
********************************************************************/
void randomPlacement() {
	int row, col, percent;

	srand(time(NULL));

	fprintf(outfile, "< Board edited randomly >\n");
	printf("Please enter the percentage of the board you would like populated:  ");
	scanf("%d", &percent);

	for (row = 1; row < MAXROW + 1; ++row)
		for (col = 1; col < MAXCOL + 1; ++col)
			if ((rand( ) % 100) < percent)
				current[row][col] = '*';

	fflush(stdin);
}

/**************************************************************************
* This function simulates the game of life according to the rules:        *
*                                                                         *
* SURVIVAL – a currently occupied (living) cell survives if it has either *
*            exactly two (2) or three (3) neighbors.  (A neighbor is an   *
*            immediately adjacent array cell with a creature in it.)      *  
                      *
* DEATHS – Each occupied (living) cell with four (4) or more neighbors    *
*          dies of overcrowding.  Each occupied (living) cells with one or*
*          less neighbors dies of loneliness.                             *
* BIRTHS – An empty cell will give birth to a new creature IF, and ONLY IF*
*          it has EXACTLY three (3) neighbors.                            *
***************************************************************************/
void simulateLife() {
	int row, col, num_neighbors;

	++num_generation;
	for (row = 1; row < MAXROW + 1; ++row)
		for (col = 1; col < MAXCOL + 1; ++col)
		{
			num_neighbors = 0;
			if (current[row - 1][col - 1] == '*')
				++num_neighbors;
			if (current[row - 1][col] == '*')
				++num_neighbors;
			if (current[row - 1][col + 1] == '*')
				++num_neighbors;
			if (current[row][col - 1] == '*')
				++num_neighbors;
			if (current[row][col + 1] == '*')
				++num_neighbors;
			if (current[row + 1][col - 1] == '*')
				++num_neighbors;
			if (current[row + 1][col] == '*')
				++num_neighbors;
			if (current[row + 1][col + 1] == '*')
				++num_neighbors;

			if (num_neighbors <= 1) /* dies of loneliness */
				next[row][col] = '-';
			else if (num_neighbors >= 4) /* dies of overcrowding*/
				next[row][col] = '-';
			else if (num_neighbors == 3) /* birth */
				next[row][col] = '*';
			else /* survives */
				next[row][col] = current[row][col];
		}
}
