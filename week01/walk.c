/*************************************************************
*
*  Mason Jensen
*  01/20/2007
*
*  Walk.c - This program will create a DIMxDIM game board.  
*  Next it will randomly select a beginning position anywhere 
*  on the board.  Beginning with the letter A, it will 
*  populate the squares with the alphabet while randomly 
*  moving up, down, left, or right.  If it becomes blocked in 
*  it will stop.  The success or fail outcome is reported, and
*  the board is printed.
*
*************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define _CRT_SECURE_NO_DEPRECATE
#define DIM 10

void setup_board(int board[DIM][DIM]);
void print_board(int board[DIM][DIM], int label);
void walk_board(int board[DIM][DIM], int *label);
int move_possible(int board[DIM][DIM], int row, int col);
int valid_move(int board[DIM][DIM], int row, int col, int next_move);
int roll(void);

void main(void)
{
   int arrBoard[DIM][DIM];
   int current_label = 'A';

   srand(time(NULL));
   setup_board(arrBoard);
   walk_board(arrBoard, &current_label);
   print_board(arrBoard, current_label);
}

/************************************************************
*  walkboard will roll the dice and move around from the 
*  starting position so long as there are places left to 
*  move.  On exit, label will be the value of the last 
*  successfully placed letter.
*  
*  Moving directions:
*  0 - up
*  1 - down
*  2 - left
*  3 - right
************************************************************/
void walk_board(int board[DIM][DIM], int *label)
{
   int row = rand() % 10;
   int col = rand() % 10;
   int next_move;

   board[row][col] = *label;
   while ((*label < 'Z') && move_possible(board, row, col))
   {
      do {
         next_move = roll();
      } while (!valid_move(board, row, col, next_move));

      switch (next_move)
      {
         case 0:
            --row;
            break;
         case 1:
            ++row;
            break;
         case 2:
            --col;
            break;
         case 3:
            ++col;
            break;
      }
      board[row][col] = ++(*label);
   } 

}

/************************************************************
*  move_possible returns a non-zero if the coordinates point 
*  to a location on the board with a vacant adjacent space.
************************************************************/
int move_possible(int board[DIM][DIM], int row, int col)
{
   if ((row - 1 >= 0) && (board[row - 1][col] == '-'))
      return 1;
   else if ((row + 1 < DIM) && (board[row + 1][col] == '-'))
      return 1;
   else if ((col - 1 >= 0) && (board[row][col - 1] == '-'))
      return 1;
   else if ((col + 1 < DIM) && (board[row][col + 1] == '-'))
      return 1;
   else
      return 0;
}

/************************************************************
*  valid_move returns a non-zero if the next move is to a 
*  vacant square.
*
*  Moving directions:
*  0 - up
*  1 - down
*  2 - left
*  3 - right
************************************************************/
int valid_move(int board[DIM][DIM], int row, int col, int next_move)
{
   switch (next_move)
   {
      case 0:
         --row;
         break;
      case 1:
         ++row;
         break;
      case 2:
         --col;
         break;
      case 3:
         ++col;
         break;
   }

   if ((row >= 0) && (row < DIM) && (col >= 0) && (col < DIM))
      if (board[row][col] == '-')
         return 1;
      else
         return 0;
   else
      return 0;
}

/************************************************************
*  print_board prints the board in its current state
************************************************************/
void print_board(int board[DIM][DIM], int label)
{
   int i, j;

   printf("\n");
   for (i = 0; i < DIM; ++i)
   {
      for (j = 0; j < DIM; ++j)
      {
         printf("%5c", board[i][j]);
      }
      printf("\n");
   }
   printf("\n");

   if (label == 'Z')
      printf("Success!  The random walk completed.\n");
   else
      printf("%c is blocked on all sides, cannot place %c.\n", label, label + 1);
}

/************************************************************
*  setup_board initiates all squares of the board to '-'
************************************************************/
void setup_board(int board[DIM][DIM])
{
   int i, j;

   for (i=0; i<DIM; ++i)
      for (j=0; j<DIM; ++j)
         board[i][j] = '-';
}

/************************************************************
*  roll acts as the dice roll that randomly determines the 
*  next direction to move.
************************************************************/
int roll(void)
{
   return rand() % 4;
}
