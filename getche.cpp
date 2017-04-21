/**************************************************************
* This program reads one character at a time from stdin and   *
* only allows the user to enter 5 characters into the input   *
* string.  If the user enters more than 5 characters it       *
* lets the user know that they have exceeded the limit and    *
* allows them to try again.                                   *
**************************************************************/
#include <conio.h>
#include <stdio.h>

int main()
{
	char str[6];
	int i = 0;

	do 
	{	str[i] = _getche();
	    if ( i == 5 && str[i] != 13) { 
			printf("\n\n\a\a\a\a\a\aYou exceeding limit of 5 characters. Press enter to try again.\n\n");
			fflush(stdin);
			getchar();
			i = 0;
		}
		else
			i++;
	} while ( str[i-1]!= 13); 
	
	str[i-1] = '\0';
	printf("\n\nNew String: %s\n", str );
}
