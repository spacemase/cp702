/* pointerToFunction.c */
#include <stdio.h>
#include <string.h>

typedef int (*FUNCPTR)(void *field1, void *field2);
int compareInt(int *a, int *b);
int compareStr(char *str1, char *str2);
void generalCompare ( void *field1,
                      void *field2,
					  FUNCPTR f);
					  //int (*f) (void *field1, void *field2);

void main () {

   int a,b,choice;
   char str1[10], str2[10];

   while (choice != 3) {
      printf("Enter 1 to compare integers or 2 to compare strings or 3 to quit> ");
	  scanf("%d", &choice);
	  while (getchar() != '\n');

	  if (choice == 1) {
	     printf("Enter the two integers: ");
         scanf("%d%d", &a, &b);
		 generalCompare(&a, &b, compareInt);
		 while (getchar() != '\n');
      }
	  else
		 if (choice == 2) {
			printf("Enter the first string: ");
            gets(str1);
		    printf("Enter the second string: ");
            gets(str2);
			generalCompare(str1, str2, compareStr);
		 }
   }
}

int compareInt(int *a, int *b) {
   return (*a - *b);
}

int compareStr(char *str1, char *str2) {
   return (strcmp(str1, str2));
}

void generalCompare(void *a, void *b, FUNCPTR compare) {
//void generalCompare(void *a, void *b, int (*compare)(void *field1, void *field2)){
   
   int result;
   if ( (result = (*compare)(a,b)) < 0 )    //compare(a,b)
      printf("\na < b\n\n");
   else
      if ( (result = (*compare)(a,b)) > 0 )  //compare(a,b)
         printf("\na > b\n\n");
	  else
         printf("\na = b\n\n");
}