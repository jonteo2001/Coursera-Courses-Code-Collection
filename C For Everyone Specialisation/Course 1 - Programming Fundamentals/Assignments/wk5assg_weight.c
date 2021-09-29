/* Program to find the average weight of
elephant seals by means of an array to compute the average

Jonathan Teo
C4E Course 1 Week 5 Assignment
24 OCT 2020
*/
//---------------------------------
/*Defining relevant variables, calling function prototypes*/
#include <stdio.h>
#include <stdlib.h>
double avg_weight(int x[], size_t);
void informaltests();
//MAIN CODE
int main (void)
{
  int debug = 0; //declaration of variable used to debug implementation
  /*printf("------------Running Informal Tests-------------------\n");
  informaltests();
  //To stop the code, in case function informal tests gives an error.
  printf("-----------------------------------------------------\n");
  printf("Program paused. Check if program output is correct before proceeding. \n Enter any integer to continue:\t");
  scanf("%d", &debug);
  */
  //OBTAINING DATA FILE
  printf("\n----------------Obtaining Data From File------------------\n");
  FILE* fp; //pointer to file
  //int count = 0;
  fp = fopen("elephant_seal_data.txt","r"); //open file in read only mode
  if (fp == NULL) {printf("Error! Could not open file.\n");}
  else
  {
    int check = fgetc(fp);
    while (check != EOF)
    {
      printf("%c", check);
      check = fgetc(fp);
    //  count = count + 1;
      //to track the no. of data printed, hence determine required length of the array
    }
  }
  fclose(fp); //close the file since fp is now at EOF
  //printf("\nCount = %d\n", count);
  printf("-----------------------------------------------------\n");
  printf("Program paused. Check if program output is correct before proceeding. \n Enter any integer to continue:\t");
  scanf("%d", &debug);
  //Passing Data into Array
  printf("\n----------------Read File into Array---------------\n");
  int count = 1000;
  int seals_weight[count]; //array to store weight
  FILE* fp2;
  fp2 = fopen("elephant_seal_data.txt","r");
  printf("Count = %zu\n", (sizeof(seals_weight)/sizeof(seals_weight[0])));
  for (int i = 0; i < count; i++)
  {
    fscanf(fp2, "%d", &seals_weight[i]);
  }
  fclose(fp2);
  printf("Some weights of seals are: ");
  for (int i = 900; i < 1000; i++)
  {
    printf("%d\t", seals_weight[i]);
  }
  printf("----------------------------------------------------\n");
  printf("Program paused. Check if program output is correct before proceeding. \n Enter any integer to continue: \t");
  scanf("%d", &debug);
  //Finding avg weight of seals
  printf("\n---------------Finding avg weight of seals--------------\n");
  double avg_seal = avg_weight(seals_weight, (sizeof(seals_weight)/sizeof(seals_weight[0])));
  printf("Weight of a elephant seal on avg is %lf. \n", avg_seal);
  return (0);
}


//---- DEFINITION OF FUNCTIONS BELOW---//
//Function avg_weight
double avg_weight(int x[], size_t SIZE){
  //Declaring local variables
  double sum = 0.000;
  double avg = 0.000;
  //To compute sum & avg
  for (int i = 0; i < SIZE; i++)
  {
    sum += x[i];
  }
  avg = sum/SIZE;
  printf("The size of the array is %zu.\n Sum is %lf. \n Average calculated is %lf.\n", SIZE, sum, avg);
  return (avg);
}
//Function Informaltests
void informaltests(){
  int data[10] = {1,2,3,4,5,6,7,8,9,10};
  double result = avg_weight(data, (sizeof(data)/sizeof(data[0])));
  printf("Sample data used: ");
  for (int i = 0; i < 10; i++){
    printf("%d\t", data[i]);
  }
  printf("\nAverage value should be 5.5.\nResult from informaltests(): %lf.\n", result);
  return;
}
