/* fpointer2.c */
#include <stdio.h>
#include <ctype.h>

int doubled(int);
int trebled(int);
int squared(int);
int cubed(int);

int main (void) {
   int number;
   char function[15];
   char letter;
   int (*fptr)(int);  /* pointer to function taking and returning an int */


   printf("Type an integer and either \"double\", \"triple\", \"square\", or \"cube\"\n");
   while (scanf("%d%s", &number, function) == 2) {

	   /* turn first letter of array into caps */
	   letter = toupper(function[0]);

	   switch(letter) {
	      case 'D': fptr = doubled;
		     break;
          case 'T': fptr = trebled;
		     break;
	      case 'S': fptr = squared;
		     break;
	      case 'C': fptr = cubed;
		     break;
	      default:
	         printf("Incorrect choice; try again\n");
       }

	   printf("%d %s%c is %d\n", number, function, 'd', (*fptr)(number));
	   //printf("%d %s%c is %d\n", number, function, 'd', fptr(number));
	   printf("Type an integer and either \"double\", \"triple\", \"square\", or \"cube\"\n");
	   printf("Type Q to quit\n");
   }
}

int doubled(int num) {
	return num * 2;
}

int trebled(int num) {
	return num * 3;
}

int squared(int num) {
	return num * num;
}

int cubed(int num) {
	return num * num * num;
}