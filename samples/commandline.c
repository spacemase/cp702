#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( int argc, char *argv[ ] ) {
   int x;
   double y;
   FILE *input;
   char oper[11];
   
   if ( argc != 4) {
   	  printf( "Need to enter filename, integer and double\n");
	  return EXIT_FAILURE;
   }

   if ( (input = fopen(argv[1],"r")) == NULL ) {
      printf("Can't open input file: %s\n", argv[1]);
      exit(1);
   }
	  
   x = atoi( argv[2] );
   y = atof( argv[3] );

   fgets(oper, 10, input); 

   if (strcmp(oper,"ADD"))
      printf("%5.2f -  %5.2f = %5.2f\n\n", (double)x, y, (double)x - y );
   else
      printf("%5.2f +  %5.2f = %5.2f\n\n", (double)x, y, (double)x + y );
   
   return EXIT_SUCCESS;
}
