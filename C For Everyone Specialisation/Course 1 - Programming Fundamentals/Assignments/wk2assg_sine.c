//Include Relevant Libraries
#include <stdio.h>
//Define Relevant Constants
#define PI 3.14159653

/* For 0<=x<=1, sin (x) is accurate up to and including the x^5 term of
Taylor Series.
Hence, sin (x) approximately equals to x - x^3/3! + x^5/5!, where 3! = 6 and 5! 120
*/
//Main Code
int main (void) {
  //Declaring variables
  long double x, sine;
  //To Run Informal Tests
  printf("Testing the function............................................\n");
  printf("These 2 outputs should match. \n ");
  x = PI/4; sine = x - (x*x*x)/6 + (x*x*x*x*x)/120;
  printf("sine when x = PI/4 = 0.707. Answer: %Lf\n", sine);
  x = PI/6; sine = x - (x*x*x)/6 + (x*x*x*x*x)/120;
  printf("sine when x = PI/6 = 0.500. Answer: %Lf\n", sine);
  x = 0; sine = x - (x*x*x)/6 + (x*x*x*x*x)/120;
  printf("sine when x = 0 = 0. Answer: %Lf\n", sine);
  x = 1; sine = x - (x*x*x)/6 + (x*x*x*x*x)/120;
  printf("sine when x = 1 = 0.842. Answer: %Lf\n", sine);
  //End of tests
  //Reinitialising the value of x to -1 to kickstart the while loop
  x = -1.0; sine = 0.0;
  while (x < 0 || x > 1){
    printf("Input a value of x between 0 and 1: ");
    scanf("%Lf", &x);
  }
  sine = x - (x*x*x)/6 + (x*x*x*x*x)/120;
  printf("Sine of %Lf is %Lf\n", x, sine);
  return 0;
}
