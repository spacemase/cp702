/************************************************************
*
*  Mason Jensen
*  February 18, 2007
*
*  student_grades.c
*
*  This program performs the following:
*
*  Externally define a name structure template with two 
*  members: a string that holds the first name (20 characters) 
*  and a string that holds the second name (20 characters).  
*
*  Externally define a student structure template with three 
*  members:  a name structure, a grade array to hold 3 
*  floating-point scores, and a variable to hold the average 
*  of those three scores.  
*
*  Have the main() function declare an array of CSIZE (with 
*  CSIZE = 4) student structures and initialize the name 
*  portions to names of your choice.  Use four separate 
*  functions to perform the four tasks described next.  
*
*  Interactively acquire scores for each student by prompting 
*  the user with a student name and a request for 3 scores.  
*  (Validate the input.)  Place the scores in the grade array 
*  portion of the appropriate structure.  The required looping 
*  should be done in the function, not main().  
*
*  Calculate the average score value for each student and 
*  assign it to the proper structure member.  
*
*  Print the information in each structure.  
*
*  Print the class average for each of the numeric structure 
*  members.  
*
************************************************************/

#define _CRT_SECURE_NO_DEPRECATE 1
#include <stdio.h>

#define CSIZE 4
#define NUM_ASSIGNMENTS 3
#define MAX_LENGTH 20

struct my_name{
	char first_name[MAX_LENGTH];
	char last_name[MAX_LENGTH];
};

struct student{
	struct my_name name;
	float grade[NUM_ASSIGNMENTS];
	float grade_average;
};

void get_scores(struct student student_list[]);
void calculate_averages(struct student student_list[]);
void print_grades(struct student student_list[]);
void print_class_average(struct student student_list[]);

void main(void)
{
	struct student stuArray[CSIZE] = { { {"Joey", "Benitez"},0,0,0,0 },
									   { {"Dan", "Wilson"}  ,0,0,0,0 },
									   { {"Sam", "Parker"}  ,0,0,0,0 },
									   { {"Karen", "White"} ,0,0,0,0 }
	};

	get_scores(stuArray);
	calculate_averages(stuArray);
	print_grades(stuArray);
	print_class_average(stuArray);
}

/************************************************************
*  Interactively acquire scores for each student by prompting 
*  the user with a student name and a request for 3 scores.  
*  (Validate the input.)  Place the scores in the grade array 
*  portion of the appropriate structure.  The required looping 
*  should be done in the function, not main().  
************************************************************/
void get_scores(struct student student_list[])
{
	int i;

	for (i = 0; i < CSIZE; ++i)
	{
		printf("Enter the three scores for %s %s:  ", student_list[i].name.first_name, student_list[i].name.last_name);
		while(scanf("%f%f%f", &student_list[i].grade[0], &student_list[i].grade[1], &student_list[i].grade[2]) != 3)
		{
			printf("You entered incorrect data, please try again:  ");
			fflush(stdin);
		}
	}
}

/************************************************************
*  Calculate the average score value for each student and 
*  assign it to the proper structure member.  
************************************************************/
void calculate_averages(struct student student_list[])
{
	int i, j;
	float temp = 0;

	for (i = 0; i < CSIZE; ++i)
	{
		for (j = 0; j < NUM_ASSIGNMENTS; ++j)
			temp += student_list[i].grade[j];
		student_list[i].grade_average = temp / NUM_ASSIGNMENTS;
		temp = 0;
	}
}

/************************************************************
*  Print the information in each structure.  
************************************************************/
void print_grades(struct student student_list[])
{
	int i = 0, j;

	for (i = 0; i < CSIZE; ++i)
	{
		printf("\n%s %s\t", student_list[i].name.first_name, student_list[i].name.last_name);
		for (j = 0; j < NUM_ASSIGNMENTS; ++j)
			printf("%8.2f", student_list[i].grade[j]);
		printf("%8.2f", student_list[i].grade_average);
	}
	printf("\n");
}

/************************************************************
*  Print the class average for each of the numeric structure 
*  members.  
************************************************************/
void print_class_average(struct student student_list[])
{
	int i, j;
	float class_grade[NUM_ASSIGNMENTS];
	float class_grade_average = 0;

	for (i = 0; i < NUM_ASSIGNMENTS; ++i)
	{
		class_grade[i] = 0;
		for (j = 0; j < CSIZE; ++j)
			class_grade[i] += student_list[j].grade[i];
		class_grade[i] /= CSIZE;
		class_grade_average += class_grade[i];
	}
	class_grade_average /= NUM_ASSIGNMENTS;

	printf("\nClass Averages\t");
	for (i = 0; i < NUM_ASSIGNMENTS; ++i)
		printf("%8.2f", class_grade[i]);
	printf("%8.2f", class_grade_average);
	printf("\n\n\n");
}
