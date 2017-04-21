/*******************************************************************************	
 *  Course:	      BUSCP 241 Programming in C                                   *
 *  Program Name: ASSIGN3.C                                                    *
 *  Author:	      Joey Benitez                                                 *
 *  Date:	      October 27, 2005                                             *          
 *  Description:  This program computes a set of employee's pay stubs.         *
 *                The program request the user to enter the yearly salary.     *
 *                It computes and displays the gross pay, total tax, and       *
 *                net pay for each employee. The user will terminates the      *
 *                program by entering (ctrl+Z) for the salary.                 *
 ******************************************************************************/
#include <stdio.h>

#define   FIT_TAX_RATE    .15
#define   FICA_TAX_RATE   .078

double get_salary();
double get_total_tax(double gross_pay);
void print_results(double gross_pay, double total_tax);

void main() {

   double gross_pay, total_tax;
		
   /* Loop to compute pay stub  until user enters ctrl+Z. */
   while ((gross_pay = get_salary()) != EOF) {
      total_tax = get_total_tax(gross_pay);
	  print_results(gross_pay, total_tax);
   }
}


/***********************************************************************************
*  This function requests and edits the user's input for salary. The salary should *
*  be greater than $0 and less than $150,000.  The function will return the salary *
***********************************************************************************/
double get_salary() {

   double salary;
   int n, need_salary = 1;

   while (need_salary) {
      printf("\n\nEnter yearly salary: ");
      n = scanf("%lf", &salary);

      if (n == 1)
         if ( salary <= 0 )
            printf("*** Invalid Salary - Salary must be greater than 0 ***\n");
		 else
		    if (salary >= 150000)
		       printf("*** Invalid Salary - Salary must be less than 150000 ***\n");
			else
			   need_salary = 0;
      else
	     if (n==0) {
		    printf("*** Invalid Salary - Salary is non_numeric ***\n");
			fflush(stdin);
         }
		 else {
		    salary = -1;
		    need_salary = 0;
		 }
   }
   return (salary);
}


/*******************************************************
*  This function calculates and return the total tax.  *
*******************************************************/
double get_total_tax(double gross_pay) {

   double fit_tax, fica_tax, total_tax;

   fit_tax = gross_pay * FIT_TAX_RATE;
   fica_tax = gross_pay * FICA_TAX_RATE;
   total_tax = fit_tax + fica_tax;

   return (total_tax);
}


/****************************************************************
*  This function prints the gross pay, total tax, and net pay   *
****************************************************************/
void print_results(double gross_pay, double total_tax) {
	
   printf("\nGross Pay:\t$%9.2f", gross_pay);
   printf("\nTotal Tax:\t$%9.2f", total_tax);
   printf("\nNet Pay:\t$%9.2f\n", gross_pay - total_tax );
}

	

