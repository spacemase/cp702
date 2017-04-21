/****************************************************************************
* Description:  This program reads a binary input file containing a list of *
*               movies and their ratings and builds a link list.  It then   *
*               allows the user to add and/or delete movies from the list.  *
*               After all of the additions/deletions, it creates a new file *
*               containing the updated list.                                *
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct movie {
    char title[TSIZE];
    int rating;
};
typedef struct movie Item;

typedef struct node {
    Item item;
    struct node * next;
} Node;
typedef Node * List;

char getOption();
void initializeList(List * plist);
void printList(List plist);
void addMovie(List * plist);
void deleteMovie(List * plist);
void createListFile(List plist);
  
FILE * inputPtr, * outputPtr; 

   
int main() {
	
   List plist;
   char option;

   // Read movie file and create link list. 
   initializeList(&plist);
   
   // Add, delete, or print movies from the list. 
   option = getOption();
   while ( option != 'Q' && option != 'q' ) {
      switch ( option ) {
         case 'A':
         case 'a':
            addMovie(&plist);
            break;
         case 'D':
         case 'd':
            deleteMovie(&plist);
            break;
         case 'P':
         case 'p':
            printList(plist);
            break;
         default:
            printf("\nIncorrect option, please try again.\n");
       }
        
       option = getOption();
   }
  
   // Create new movie file from link list. 
   createListFile(plist);
  
   return EXIT_SUCCESS;
}

  
/************************************************************************** 
* This function displays the option menu and returns the users selection. *
**************************************************************************/
char getOption() {
   char option;
    
   printf("\nPlease enter A to add a movie,\n");
   printf("             D to delete a movie,\n");
   printf("             P to print the movie list\n");
   printf("             Q to quit\n ");
   printf("    Option> ");
   scanf_s("%c", &option);
   while ( getchar() != '\n');
   
   return (option);
}
  
  
/**************************************************************************
* This function reads an input file containing a list of movies and their *
* ratings and builds a link list.  If no file exists or if the file is    *
* empty then the list pointer is set to NULL.                             * 
**************************************************************************/
void initializeList(List * plist) {

   int i = 1;
   Item temp;
   List pnew;
   List pprev;

   *plist = NULL;

   if (fopen_s(&inputPtr,"movie.dat","rb")) {
      printf("No input file --- movie.dat file\n");
      return;
   }

   pnew = (Node *) malloc(sizeof(Node));
   while ( fread(&temp, sizeof(Item), 1, inputPtr) == 1 ) {
      pnew->item = temp;
      pnew->next = NULL;
      if ( i != 1 )
	     pprev->next = pnew;
      else
	  {
		 *plist = pnew;
	     i++;
	  }
	  pprev = pnew;
	  pnew = (Node *) malloc(sizeof(Node));
   }
   fclose(inputPtr);
}

   
/**************************************************************************
* This function prompts the user for a movie and rating and builds a node *
* and adds it to the link list in alphabetical order.                     *
**************************************************************************/
void addMovie(List * plist) {
}

   
/************************************************************************
* This function prompts the user for a movie and rating and deletes the *
* node from the link list.                                              *
**************************************************************************/
void deleteMovie(List * plist) {
   int titleNotFound = 1;
   Item temp;
   List pprev, pcurr;

   pprev = *plist;
   pcurr = *plist;

   // If the list is empty then print message and return to main. 
   if (pcurr == NULL ) {
      printf("\nThe list is empty\n");
      return;
   }
  
   printf("\nEnter movie title> ");
   gets_s(temp.title, 45);

   // If node to delete is first node then reset list pointer. 
   if ( _stricmp(temp.title, pcurr->item.title) == 0 ) {
      *plist = pcurr->next;
      titleNotFound = 0;
   }
   else
      while ( pcurr != NULL && titleNotFound )
         if ( _stricmp(temp.title, pcurr->item.title) > 0 ) {
            pprev = pcurr;
            pcurr = pcurr->next;
         }
         else
            if ( _stricmp(temp.title, pcurr->item.title) == 0 ) {
               titleNotFound = 0;
               pprev->next = pcurr->next;
               free(pcurr);
            }
            else
               break;
  
   if ( titleNotFound )
      printf("\nMovie not found in list\n");
   else
      printf("%s was successfully deleted from the movie list\n", temp.title);
}

   
/*********************************************************************
* This function creates a file containing a list of movies and their *
* ratings from a link list.                                          *
*********************************************************************/
void createListFile(List plist) {
    
   Item temp;

   if (fopen_s(&outputPtr, "movie.dat","wb")) {
      printf("Can't open movie.dat file\n");
      exit(1);
   }

   while ( plist != NULL ) {
      temp = plist->item;
      fwrite(&temp, sizeof(Item), 1, outputPtr);
      plist = plist->next;
   }
   fclose(outputPtr);
}
   
   
/*******************************************************************
* This function prints the list of movies and their ratings from a *
* link list.                                                       *
*******************************************************************/
void printList(List plist) {
  
   Item temp;
  
   printf("\n");
   if ( plist != NULL )
      while ( plist != NULL ) {
         temp = plist->item;
         printf("Title: %-45s  Rating: %d\n", temp.title, temp.rating);
         plist = plist->next;
      }
   else
      printf("No data found in list.\n");
}
