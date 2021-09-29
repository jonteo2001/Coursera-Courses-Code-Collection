/*
JONATHAN TEO
29 OCT 2020
WEEK 4 ASSIGNMENT OPTION 1
--------------------- INSTRUCTIONS ----------------------
Open and read a file of integers into an array that
is created with the first integer telling you how many to read.

So  4  9  11  12  15  would mean create an int array size 4
and read in the remaining 4 values into data[].

Then compute their average as a double and their max  as an int.
Print all this out neatly to the screen AND to an output file named answer-hw3.
//Use elephant_seals data file
-------------------------------------------------------------------------
*/
//Including relevant libraries
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define NDEBUG

/*Functions
- 1 function to compute manipulation (avg, max, min), manipulation () & prints it to the screen
- 1 function that accepts file ptr as a parameter and checks to see if file is readable
- 1 function that passes data from text file into array (in main)
- 1 function that passes data back into a text file (in main)
- 1 function to get a size from a text file - first integer of the file
- 1 function to test the program informally.
- Function main
*/
void writefile(FILE*ptr, int max, int min, double avg)
{
    fprintf(ptr, "Average: %lf\t Max: %d\t Min: %d\t\n", avg, max, min);
    printf("File printed! Check Output file at the next break in the program.");
    return;
}
void manipulation(int x[], int size, FILE*ptr)
{
  printf("\n----------------- RUNNING MANIPULATION() --------------------\n");
  int count = size -1;
  int max = -1, min = 2147483647;
  double sum = -1.0, avg;// min = 2^32-1 - max value for signed integers
  for (int i = 1; i < size; i++)
  { //CODE part 1 - calculate max
    if (x[i] > max) { max = x[i];}
    if (x[i] < min) { min = x[i];}
    sum = sum + x[i];
  }
  avg = sum / count;
  printf("Sample count: %d\t Average: %lf\t Max: %d\t Min: %d\t\n",
  count, avg, max, min);
  writefile(ptr, max, min, avg);
  return;
}
void print_file(FILE* ptr)
{
  printf("\n----------------- RUNNING PRINTFILE() --------------------\n");
  int c;
  rewind(ptr);
  while ((c = getc(ptr))!=EOF)
  {
    putc(c,stdout);
  }
}

int getSize(FILE *ptr)
{
  printf("\n ---------------- RUNNING GETSIZE()--------------\n");
  int array_size = -1;
  rewind(ptr);
  fscanf(ptr, "%d", &array_size);
  return (array_size+1);
}
void FileToArray(FILE*fp, int *ptr, int array_size) //initalising array with a size larger than
{
  printf("\n ---------------- RUNNING FILETOARRAY()-----------\n");
  int count = array_size;
  printf("sizeof(int):%zu", sizeof(int));
  rewind(fp); // rewind all pointers
  for (int i = 0; i < count; i++)
  {
    fscanf(fp, "%d", ptr+i);
    if(*ptr == 4 || *ptr == 330) {continue;}
  }
}
void informalTests()
{
  int debug;
  printf("\n---------------- RUNNING INFORMAL TESTS ------------- \n");
  FILE *fp, *out;
  fp = fopen("sample_data.txt", "r");
  out = fopen("sample-output.txt", "w");
  printf("\n---------------- PRINTING SAMPLE DATA ------------- \n");
  print_file(fp);
  printf("\n------------------------------------------\n");
  printf("\n Program Paused. Check that output is 4 	9 	11 	12 	15.\n Enter any integer to continue:");
  scanf("%d", &debug);
  printf("\n---------------- GETTING THE SIZE OF ARRAY ---------- \n");
  int size = getSize(fp);
  printf("Size should be equal to 4. \n Array Size: %d. \n Enter any integer to continue:", size);
  scanf("%d", &debug);
  int data[size];
  int *arr_ptr = &data[0];
  printf("\n --------------- READ FILE INTO ARRAY -------------- \n");
  FileToArray(fp, arr_ptr, size);
  printf("Printing Array:");
  for (int i = 0; i < size; i++)
  {
    printf("data[%d]= %d\n", i, data[i]);
  }
  printf("\n------------------------------------------\n");
  printf("\n Program Paused. Check that output is 9 	11 	12 	15.\n Enter any integer to continue:");
  scanf("%d", &debug);
  printf("\n --------------- FINDING AVG, MAX & MIN OF ARRAY DATA ---------\n");
  manipulation(data, size, out);
  printf("\n------------------------------------------\n");
  printf("\n Program Paused. Check that\n Avg: 11.75\n Min: 9\n Max: 15\n Enter any integer to continue");
  scanf("%d", &debug);
  printf("\n ------------RETURNING BACK TO PROGRAM-----------\n");
  return;
}
//MAIN CODE BODY
int main (int argc, char* argv[])
{
  informalTests();
  FILE *ifp, *ofp;
  if (argc != 3)
  {
    printf("Need executable inputfile ouputfile!\n");
    exit(1);
  }
  ifp = fopen(argv[1], "r+");// read and write-able, cuz
  ofp = fopen(argv[2], "w+"); //
  printf("my %s file as read is \n\n", argv[1]);
  print_file(ifp);//input file
  printf("\n\n");
  int array_size = getSize(ifp);//Get array size
  int array[array_size]; //Initialise vector of array size
  int* arr_ptr = &array[0];
  FileToArray(ifp, arr_ptr, array_size);
  manipulation(array, array_size, ofp);//manipulate the result and write to the output file
  fclose(ifp); fclose(ofp); return (0);
}
