/*******************************************************************************
* Course:       C Intermediate Programming                                     *
*                                                                              *
* Program Name: Assignment7A.c                                                  *
*                                                                              *
* Author:       your name                                                      *
*                                                                              *
* Date:         June 1, 2002                                                   *
*                                                                              *
* Description:  This program simulates an airlines reservation system.  It     *
*               consists of one plane with a seating capacity of 12.  It       *
*               makes one flight daily.                                        *
*                                                                              *
*               The program uses an array of 12 structures.  Each structure    *
*               holda a seat identification number (1A, 1B, 2A, 2B, ... 6A,    *
*               6B), a marker that indicates whether the seat is assigned,     *
*               the last name of the seat holder, and the first name of the    *
*               seat holder.                                                   *
*                                                                              *
*               The program displays the following menu:                       *
*                                                                              *
*               To choose a function, enter its letter label:                  *
*               a)	Show number of empty seats                                 *
*               b)	Show list of empty seats                                   *
*               c)	Show alphabetical list of assigned seats and customer name *
*               d)	Assign a customer to a seat assignment                     *
*               e)	Delete a seat assignment                                   *
*               f)	Quit                                                       *
*                                                                              *
*               The program successfully executes the promises of its menu.    *
*               Choices d) and e) require additional input, and each enables   *
*               the user to abort entry.                                       *
*                                                                              *
*               After executing a particular function, the program shows the   *
*               menu again, except for choice f).                              *
*                                                                              *
*               Data is saved in a file between runs.  When the program is     *
*               restarted, it first loads in the data, if any, from the file.  *
*                                                                              *
*******************************************************************************/
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;
#define SIZE 12

struct reservation {
   char seat[4];
   char lastName[20];
   char firstName[20];
   char seatMarker;
};
  
char getOption();
void readReservationFile();
void countEmptySeats();
void showEmptySeats();
void assignSeat();
void deleteSeatAssignment();
void showReservedSeats();
void loadReservationFile();

struct reservation seatArray[SIZE]  = { {"1A"," "," ",'N'}, {"1B"," "," ",'N'},
                                        {"2A"," "," ",'N'}, {"2B"," "," ",'N'},
                                        {"3A"," "," ",'N'}, {"3B"," "," ",'N'},
                                        {"4A"," "," ",'N'}, {"4B"," "," ",'N'},
                                        {"5A"," "," ",'N'}, {"5B"," "," ",'N'},
                                        {"6A"," "," ",'N'}, {"6B"," "," ",'N'} };
FILE *inputPtr, *outputPtr;
  



int main( ) {
   char option;

   //Read and Load Reservation File.
   readReservationFile();

   option = getOption();
   while ( option != 'Q' &amp;&amp; option != 'q' ) {
      switch ( option ) {
         case 'A':
         case 'a':
            countEmptySeats();
            break;
         case 'B':
         case 'b':
            showEmptySeats();
            break;
         case 'C':
         case 'c':
            showReservedSeats();
            break;
         case 'D':
         case 'd':
            assignSeat();
            break;
	 case 'E':
         case 'e':
            deleteSeatAssignment();
            break;
	 default:
            printf("\nIncorrect option, please try again.\n");
       }
        
       option = getOption();
   }
  
   //Load Reservation File.
   loadReservationFile();
}
  

/************************************************************************** 
* This function displays the option menu and returns the users selection. *
**************************************************************************/
char getOption() {
   char option;
    
   printf("\nTo choose a function, enter its letter label:\n");
   printf("a) Show number of empty seats\n");
   printf("b) Show list of empty seats\n");
   printf("c) Show alphabetical list of assigned seats and customer name\n");
   printf("d) Assign a customer to a seat assignment\n");
   printf("e) Delete a seat assignment\n");
   printf("q) Quit\n ");
   printf("&gt; ");
   scanf("%c", &amp;option);
   while ( getchar() != '\n');
   
   return (option);
}


/***********************************************************************
* This function reads an input file containing a list of reservations. *
* It contains the seat number, first name, last name, and seat marker  *
* value of 'Y'.  If no file exists processing continues.               *
***********************************************************************/
void readReservationFile() {
}
  

/***************************************************************************** 
* This function determines the number of empty seats and displays the value. *
*****************************************************************************/
void countEmptySeats() {
}


/************************************************** 
* This function displays the list of empty seats. *
**************************************************/
void showEmptySeats() {
}


/****************************************************************************
* This function lists the reserves seats, seat number, first and last name. *
****************************************************************************/
void showReservedSeats() {
}


/********************************************** 
* This function assigns a seat to a customer. *
**********************************************/
void assignSeat() {
}
 

/***************************************** 
* This function removes a reserved seat. *
*****************************************/
void deleteSeatAssignment() {
}
  

/*********************************************************** 
* This function load a file with the current reservations. *
***********************************************************/
void loadReservationFile() {
}

