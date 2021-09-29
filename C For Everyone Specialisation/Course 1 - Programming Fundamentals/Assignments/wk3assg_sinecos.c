//Including Relevant Libraries
#include <stdio.h>
#include <math.h>

//Defining Relevant Constants
#define PI 3.141592653

//Code to Test the Function
void informalTests(float x[], int n){

  printf("Testing the sine and cosine functions...................\n");
  printf("sin(0) = %f. Answer should be 0\n",sin(0));
  printf("cos(0) = %f. Answer should be 1\n",cos(0));
  printf("sin(PI/6)= %f. Answer should be 0.50\n", sin(PI/6));
  printf("cos(PI/3)= %f. Answer should be 0.50\n", cos(PI/3));

  printf("Testing the xArray.......................................\n");
  printf("size of xArray = %d\n", n);
  for (unsigned int i = 0; i < n; i++){
    printf("x values in the array are: %f\n", x[i]);
  }
  return;
}

//Main Code
int main (void){
  //Declaring local variables
  double sineArray[10], cosineArray[10];
  float xArray[10] = {0.1 , 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};
  int size = sizeof(xArray) / sizeof(xArray[0]);
  for (unsigned int i = 0; i < size; i++){
    cosineArray[i] = cos(xArray[i]);
    sineArray[i] = sin(xArray[i]);
    printf("%0.1f%lf%lf\n", xArray[i],cosineArray[i],sineArray[i]);
  }
  printf("%s\n %s\n %s\n %s\n", "For the table of values above",
  "x values are in the first column,",
  "cosine values are in the 2nd column,",
  "sine values in the last column.");
  informalTests(xArray, size);
  return 0;
}
