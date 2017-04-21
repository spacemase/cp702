/**************************************************************************
* Course:       C Intermediate Programming                                *
*                                                                         *
* Program Name: Random Number Generator                                   *
*                                                                         *
* Author:       Joey Benitez                                              *
*                                                                         *
* Date:         March 16, 2002                                            *
*                                                                         *
* Description:  This program randomly genates 10 occurrences of the       *
*               the intergers 0, 1, 2, and 3                              *
*                                                                         *
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4

void main() {

   int num, i;
	
   srand((unsigned) time(NULL));

   for ( i = 0; i < 10; i++ ) {
      num = rand() % SIZE;
      printf("%d\n", num);
   }
}