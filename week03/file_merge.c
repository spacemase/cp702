/************************************************************
*
*  Mason Jensen
*  February 4, 2007
*
*  file_merge.c:
*     Program opens three files whose names are provided by 
*  command-line arguments.  Have the program write to the 
*  third file, line 1 of the first file, line 1 of the second 
*  file, line 2 of the first file, line 2 of the second file, 
*  and so on, until the last line of the longer file (in terms 
*  of lines) is written to the third file.  Error checking 
*  is to see whether the number of arguments is correct and 
*  whether the files can be opened.
*  
*  C\> file_merge.exe input1.dat input2.dat output.dat
*  
*  Return codes:
*       0 - execution successful, no errors
*     -10 - command line arguments incorrect
*     -20 - error opening file for reading
*     -30 - error opening file for writing
*     -40 - error closing file
*     -50 - error reading from file
*     -60 - error writing to file
*     -90 - undefined error
*  
************************************************************/
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define COMMAND_LINE_ERROR -10
#define FILE_OPEN_READ_ERROR -20
#define FILE_OPEN_WRITE_ERROR -30
#define FILE_CLOSE_ERROR -40
#define FILE_READ_ERROR -50
#define FILE_WRITE_ERROR -60
#define UNDEFINED_ERROR -90

int HandleError(const int iError, const char *const sErrorMessage);
int OpenFiles(const char *const pInputFilename1, 
			  const char *const pInputFilename2, 
			  const char *const pOutputFilename);
int ReadWriteFiles(const char *const pInputFilename1,
				   const char *const pInputFilename2,
				   const char *const pOutputFilename);
int CloseFiles(const char *const pInputFilename1,
			   const char *const pInputFilename2,
			   const char *const pOutputFilename);

FILE *fpInput1 = NULL;
FILE *fpInput2 = NULL;
FILE *fpOutput = NULL;

int main(int argc, char *argv[])
{
	int intReturnCode = 0;

	if (argc != 4)
		return HandleError(COMMAND_LINE_ERROR, "");
	else
	{
		intReturnCode = OpenFiles(argv[1], argv[2], argv[3]);
		if (intReturnCode)
			return intReturnCode;
	}

	intReturnCode = ReadWriteFiles(argv[1], argv[2], argv[3]);
	if (intReturnCode)
		return intReturnCode;

	intReturnCode = CloseFiles(argv[1], argv[2], argv[3]);
	if (intReturnCode)
		return intReturnCode;

	return 0;
}

/************************************************************
*  OpenFiles:  
*     Opens read and write strings on the data files passed 
*  into the main function.
************************************************************/
int OpenFiles(const char *const pInputFilename1, 
			  const char *const pInputFilename2, 
			  const char *const pOutputFilename)
{
	if ((fpInput1 = fopen(pInputFilename1, "r")) == NULL)
		return HandleError(FILE_OPEN_READ_ERROR, pInputFilename1);

	if ((fpInput2 = fopen(pInputFilename2, "r")) == NULL)
		return HandleError(FILE_OPEN_READ_ERROR, pInputFilename2);

	if ((fpOutput = fopen(pOutputFilename, "w")) == NULL)
		return HandleError(FILE_OPEN_WRITE_ERROR, pOutputFilename);

	return 0;
}

/************************************************************
*  ReadWriteFiles:  
*     Reads from both input files until one hits EOF, writing 
*  the lines to the output file.  Then reads the remaining 
*  from the unfinished file and writes that to output file.  
************************************************************/
int ReadWriteFiles(const char *const pInputFilename1,
				   const char *const pInputFilename2,
				   const char *const pOutputFilename)
{
	char sTemp[80];

	while (!feof(fpInput1) && !feof(fpInput2))
	{
		if (fgets(sTemp, 80, fpInput1) == NULL)
			return HandleError(FILE_READ_ERROR, pInputFilename1);
		if (fputs(sTemp, fpOutput) == EOF)
			return HandleError(FILE_WRITE_ERROR, pOutputFilename);
		if (fgets(sTemp, 80, fpInput2) == NULL)
			return HandleError(FILE_READ_ERROR, pInputFilename2);
		if (fputs(sTemp, fpOutput) == EOF)
			return HandleError(FILE_WRITE_ERROR, pOutputFilename);
	}
	while (!feof(fpInput1))
	{
		if (fgets(sTemp, 80, fpInput1) == NULL)
			return HandleError(FILE_READ_ERROR, pInputFilename1);
		if (fputs(sTemp, fpOutput) == EOF)
			return HandleError(FILE_WRITE_ERROR, pOutputFilename);
	}
	while (!feof(fpInput2))
	{
		if (fgets(sTemp, 80, fpInput2) == NULL)
			return HandleError(FILE_READ_ERROR, pInputFilename2);
		if (fputs(sTemp, fpOutput) == EOF)
			return HandleError(FILE_WRITE_ERROR, pOutputFilename);
	}

	return 0;
}

/************************************************************
*  CloseFiles:  
*     Closes the file pointers setup in OpenFiles.
************************************************************/
int CloseFiles(const char *const pInputFilename1,
			   const char *const pInputFilename2,
			   const char *const pOutputFilename)
{
	if ((fclose(fpInput1)) == EOF)
		HandleError(FILE_CLOSE_ERROR, pInputFilename1);

	if ((fclose(fpInput2)) == EOF)
		HandleError(FILE_CLOSE_ERROR, pInputFilename2);

	if ((fclose(fpOutput)) == EOF)
		HandleError(FILE_CLOSE_ERROR, pOutputFilename);

	return 0;
}

/************************************************************
*  HandleError:
*     Performs error handling for file_merge.  Integer input 
*  is error code.
************************************************************/
int HandleError(const int iError, const char *const sErrorMessage)
{
	switch (iError)
	{
		case COMMAND_LINE_ERROR:
			printf("***** ERROR:  Incorrect command line arguments *****\n");
			printf("Command Reference:  \n\t");
			printf("C\\> file_merge.exe <input_file2> <input_file2> <output_file>\n\n");
			return COMMAND_LINE_ERROR;
		case  FILE_OPEN_READ_ERROR:
			printf("***** ERROR:  Failed to open file %s for reading *****\n\n", sErrorMessage);
			return FILE_OPEN_READ_ERROR;
		case FILE_OPEN_WRITE_ERROR:
			printf("***** ERROR:  Failed to open file %s for writing *****\n\n", sErrorMessage);
			return FILE_OPEN_WRITE_ERROR;
		case FILE_CLOSE_ERROR:
			printf("***** ERROR:  Failed to close file %s *****\n\n", sErrorMessage);
			return FILE_CLOSE_ERROR;
		case FILE_READ_ERROR:
			printf("***** ERROR:  Failure to read from file %s *****\n\n", sErrorMessage);
			return FILE_READ_ERROR;
		case FILE_WRITE_ERROR:
			printf("***** ERROR:  Failure to write to file %s *****\n\n", sErrorMessage);
			return FILE_WRITE_ERROR;
		default:
			printf("***** ERROR:  Undefined error:  %d *****\n", iError);
			printf("***** %s *****\n\n", sErrorMessage);
			return UNDEFINED_ERROR;
	}
}