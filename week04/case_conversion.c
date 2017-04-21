/************************************************************
*
*  Mason Jensen
*  February 11, 2007
*
*  case_conversion.c:
*     This program will allow the user to enter a word (alpha 
*  characters only) and create the word in uppercase and in 
*  lowercase and print the results.  It use bitwise 
*  manipulation to convert the original string to lowercase 
*  and uppercase.  It does NOT use the toupper, tolower, or 
*  any other string function that converts characters and/or 
*  strings to lowercase or uppercase.  Edits/validation of 
*  alpha characters and maximum string length of 20 is 
*  included.  The program allows the user to enter multiple 
*  words during one execution of the program.  
*
************************************************************/
#define _CRT_SECURE_NO_DEPRECATE 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 20

int GetString(char strUser[]);
void ToLowercase(char strLower[], char strUser[]);
void ToUppercase(char strUpper[], char strUser[]);
void PrintStrings(char strUser[], char strLower[], char strUpper[]);

void main(void)
{
	char user_string[MAX_LENGTH + 1];
	char lower_string[MAX_LENGTH + 1];
	char upper_string[MAX_LENGTH + 1];

	while (GetString(user_string))
	{
		ToLowercase(lower_string, user_string);
		ToUppercase(upper_string, user_string);
		PrintStrings(user_string, lower_string, upper_string);
	}
}

/************************************************************
*  GetString - gets the original string
************************************************************/
int GetString(char strUser[])
{
	int i;
	int bInputErr = 1;

	while  (bInputErr)
	{
		printf("Enter a word, no more than 20 alpha characters only, or ? to quit:  ");
		gets(strUser);

		if (strcmp(strUser, "?") == 0)
			return 0;

		if ((int)strlen(strUser) > MAX_LENGTH)
		{
			printf("\nYou entered more than 20 characters.  Please try again.\n");
			continue;
		}

		for (i = 0; i < (int)strlen(strUser); ++i)
		{
			if (!isalpha(strUser[i]))
			{
				printf("\nYou entered a non-alpha character.  Please try again.\n");
				break;
			}
		}
		if (i == (int)strlen(strUser))
			bInputErr = 0;
	}

	return 1;
}

/************************************************************
*  ToLowercase - receives the original string and returns a 
*  new string in lowercase
************************************************************/
void ToLowercase(char strLower[], char strUser[])
{
	int i;
	char mask = 32;

	for (i = 0; i < (int)strlen(strUser); ++i)
		strLower[i] = strUser[i] | mask;
	strLower[i] = '\0';
}

/************************************************************
*  ToUppercase - receives the original string and returns a 
*  new string in uppercase
************************************************************/
void ToUppercase(char strUpper[], char strUser[])
{
	int i;
	char mask = 32;

	for (i=0; i < (int)strlen(strUser); ++i)
		strUpper[i] = strUser[i] & ~mask;
	strUpper[i] = '\0';
}

/************************************************************
*  PrintStrings - prints the original string, the original 
*  string in lowercase, and the original string in uppercase
************************************************************/
void PrintStrings(char strUser[], char strLower[], char strUpper[])
{
	printf("Original string:  %s\n", strUser);
	printf("Lowercase string:  %s\n", strLower);
	printf("Uppercase string:  %s\n\n", strUpper);
}
