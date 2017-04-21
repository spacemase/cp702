/************************************************************
*
*  Mason Jensen
*  January 27, 2007
*
*  Assignment 2:
*  Write a program that simulates the search and replace 
*  operation in a text editor.  The program is to have only 
*  three function calls in main.  The first function prompts 
*  the user to type a string of less than 80 characters.  It 
*  then prompts the user to type the search-substring of 10 
*  or fewer characters.  Finally, it prompts the user to type 
*  the replacement-substring of 10 or fewer characters.
*
*  The second call is the search and replace function, which 
*  replaces all occurrences of the search-substring with the 
*  replacement-substring and creates a new string of the 
*  result.  If no occurrences are found it returns the 
*  original string.  Theoretically, the new string could be 
*  800 characters long (80 identical characters replaced by 
*  ten characters each).
*
*  After the search and replace function returns, a print 
*  function prints the resulting string as a series of 72 
*  character lines.
*
*  Write each called function using good structured 
*  programming techniques.  
*
*  Test your program by running the program at least three 
*  times:
*     1.	First, run it with no substitutions in the 
*			original input.
*     2.	Second, run it with two or more substitutions.
*     3.	Finally, run it with substitutions that cause 
*			the output to be at least three lines. 
*
************************************************************/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 80
#define SUB_LENGTH 10

void GetStrings(void);
void SearchAndReplace(void);
void PrintNewString(void);

char user_string[MAX_LENGTH];
char search_string[SUB_LENGTH];
char replacement_string[SUB_LENGTH];
char new_string[MAX_LENGTH * SUB_LENGTH];

void main(void)
{
   GetStrings();
   SearchAndReplace();
   PrintNewString();
}

/************************************************************
*
*  Function: GetStrings
*     Get original string
*     Get search string
*     Get replacement string
*
************************************************************/
void GetStrings(void)
{
   puts("Please enter the string to work with (under 80 characters):");
   gets(user_string);
   puts("Please enter the string to search (under 10 characters):");
   gets(search_string);
   puts("Please enter the replacement string (under 10 characters):");
   gets(replacement_string);
}

/************************************************************
*
*  Function: SearchAndReplace
*     Initialize new string to ‘\0’
*     While (search string found)
*        Place '\0' at replacement location 
*        Copy up to replacement character into newstr 
*        Append replacement charaters 
*        Point start of string after the replacement characters.
*     End-While
*     Append remaining string to new string
*
************************************************************/
void SearchAndReplace(void)
{
   char *searchPtr;
   char *startPtr = user_string;

   *new_string = '\0';
   while (searchPtr = strstr(startPtr, search_string))
   {
      *searchPtr = '\0';
      strcat(new_string, startPtr);
	  strcat(new_string, replacement_string);
	  startPtr = searchPtr + strlen(search_string);
   }
   strcat(new_string, startPtr);
}

/************************************************************
*
*  Function: PrintNewString
*     While (character not equal ‘\0’)
*        Print character of new string
*        If print count = 72
*           Print newline
*
************************************************************/
void PrintNewString(void)
{
   char *cPtr = new_string;
   int print_count = 0;

   printf("\nThe new string:\n");
   while (*cPtr != '\0')
   {
      putchar(*cPtr++);
	  if (++print_count == 72)
	  {
		  putchar('\n');
		  print_count = 0;
	  }
   }
   printf("\n\n");
}
