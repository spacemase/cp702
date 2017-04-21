#include <stdio.h>
#include <ctype.h>
#include <string.h>

void getString(char *inString);
int determineIfPalindrome(const char *inString);
void printResult(const char *inString, int isPalin);

void main(void)
{
	int isPalindrome = 0;
	char input_string[80] = {'\0'};

	getString(input_string);
	isPalindrome = determineIfPalindrome(input_string);
	printResult(input_string, isPalindrome);
}

void getString(char *inString)
{
	puts("Please enter a string of less than 80 characters:");
	gets(inString);
}

int determineIfPalindrome(const char *inString)
{
	char *pTemp;
	char *pNewString = pTemp;

	do {
		const char c = *inString;
		if (isalpha(c))
			*pTemp++ = tolower(c);
	} while (*inString++);
	*pTemp-- = '\0';

	while ((*pNewString) && (*pNewString++ == *pTemp--))
		;
	if (*pNewString == '\0')
		return 1;
	else
		return 0;
}

void printResult(const char *inString, int isPalin)
{
	printf("'%s' is %sa palindrome\n\n", inString, isPalin ? "" : "NOT ");
}
