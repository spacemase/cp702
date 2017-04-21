/**************************************************************************
* Course:       C Intermediate Programming                                *
*                                                                         *
* Program Name: Assignment #1                                             *
*                                                                         *
* Author:       Joey Benitez                                              *
*                                                                         *
* Date:         December 12, 2003                                         *
*                                                                         *
* Description:  This program generates a "random walk" across a 10 X 10   *
*               array.  The array will contain characters, all set to '-' *
*               initially.  The program must randomly "walk" from element *
*               to element, always going up, down, left, or right by one  *
*               element.  The  elements  visited  by the program will be  *
*               labeled  with  the letters A through Z, in order visited. *
*               Before  performing  a  move,  check that (a) it won't go  *
*               outside  the  array, and  (b)  it  doesn't take us to an  *
*               element  that  already  has a letter assigned.  If either *
*               condition  is  violated,  try  moving  in  another random *
*               direction.  If  all  four  directions  are  blocked,  the *
*               program must terminate with an appropriate message.       *
*                                                                         *
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

/***** Function Prototypes *****/
void initializeArray(int *row, int*col);
void enterNextMove(int *row, int *col, char letter);
int  determineIfBlocked(int row, int col);
void printResults(char letter);

/***** Array Declarations  *****/
char walk[SIZE][SIZE];


/*************************   MAIN   *******************************/
void main() {

   int row, col, stillMoving = 1;
   char letter = 'B';
   
   srand((unsigned) time(NULL));

   initializeArray(&row, &col);

   while ( letter <= 'Z' && stillMoving ) {
	  enterNextMove(&row, &col, letter);
	  stillMoving = determineIfBlocked(row,col);
	  letter++;
   }

   printResults(letter);
}


/*********************************************************************
*  This function initializes the walk array to '-' and randomly      *
*  places the letter 'A'.                                            *
*********************************************************************/
void initializeArray(int *row, int *col) {
   int i,j;
 
   for ( i = 0; i < 10; i++ )  
      for ( j = 0; j < 10; j++ )
         walk[i][j] = '-';

   *row = rand() % 10;
   *col = rand() % 10;
   walk[*row][*col] = 'A';
}


/*********************************************************************
*  This function gets the next move in the random walk and inserts   *
*  the next letter into the array.                                   *
*********************************************************************/
void enterNextMove(int *row, int *col, char letter) {
   int temprow, tempcol, move, stillSearching = 1;

   while (stillSearching) {
	   
	  move = rand() % 4;
	  temprow = *row;
      tempcol = *col;

      switch (move)
	  {
         case 0:
	        temprow = *row - 1;
			break;
	     case 1:
	        tempcol = *col + 1;
			break;
	     case 2:
	        temprow = *row + 1;
			break;
	     case 3:
	        tempcol = *col - 1;
			break;
	  }

	  if (temprow>=0 && temprow<=9 && tempcol>=0 && tempcol<=9 
		             && walk[temprow][tempcol] == '-') {
         *row = temprow;
	     *col = tempcol;
		 walk[*row][*col] = letter;
		 stillSearching = 0;
	  }
   }
}


/*********************************************************************
*  This function determines if the current position in the array is  *
*  blocked in.                                                       *
*********************************************************************/
int determineIfBlocked(int row, int col) {
   int blocked = 0;

   //*****Moving UP
   if ( row > 0 ) {
	   if ( walk[row-1][col] != '-' )
		   blocked++;
   }
   else
      blocked++;

   //*****Moving DOWN
   if ( row < 9) {
	   if ( walk[row+1][col] != '-' )
		   blocked++;
   }
   else
       blocked++;

   //*****Moving LEFT
   if ( col > 0 ) {
	   if ( walk[row][col-1] != '-' )
		   blocked++;
   }
   else
      blocked++;

   //*****Moving RIGHT
   if ( col < 9 ) {
      if ( walk[row][col+1] != '-' )
		   blocked++;
	  }
   else
      blocked++;


   if ( blocked != 4 )
      return 1;
   else
      return 0;
}


/*******************************************************************************
*  This function prints the 10 X 10 walk array and an appropriate message      *
*  indicating if the random walk was completed successfully or was terminated. *
*******************************************************************************/
void printResults(char letter) {
   int i,j;
 
   printf("\n\n\n");
   for ( i = 0; i < 10; i++ ) {
      for ( j = 0; j < 10; j++ ) 
         printf("%4c", walk[i][j]);
      printf("\n");
   }

   if ( letter > 'Z' )
      printf("\n\nThe random walk was completed successfully.\n\n");
   else
      printf("\n\n%c is blocked on all four sides, so there's no place to put %c.\n\n",
	  letter -1, letter);
}



/******************************** DESIGN ***************************************

1.  Function: Initialize the array to '-' and place 'A' randomly
2.  Main: Loop while index <= 'Z' and 'still moving'
	2A. Function: Get next Move
		  2AA.  Get Random Integer 0-3
		  2AB.  Temporarily set 'next' column and row
		  2AC.  Determine if valid move -> location = '-'
		  2AD.  If not valid go back to 2AA.
		  2AE.  If valid then change row or column and return value to main
	2B. Function: Determine if Blocked.
		  2BA.  If blocked, set 'still moving' to 'N'
3.  Function: Print Results including appropriate message.

Notes:  1.  Be sure to have srand((unsigned) time(NULL)); in main.
        2.  Do NOT insert letter into row/column until you know it is valid.
		3.  In determining if blocked remember to check if row and/or column
		    to left/right/up/down is out of array.

*********************************************************************************/