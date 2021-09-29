/*
JONATHAN TEO
29 OCT 2020
department.c
WEEK 2 ASSIGNMENT
-------------------- INSTRUCTIONS ------------------
PRODUCE A STRUCT FOR EMPLOYEES WORKING IN VARIOUS DEPARTMENTS
MEMBER VARIABLES:
    -> 5 DEPARTMENT TYPES ( HR, SALES, RESEARCH, SOFTWARE & EXECUTIVE),
    where an enum will be used
    -> Salary of type int;
    -> social security number (unsigned int)

TO GENERATE 10 EMPLOYEES WITH DIFFERENT SOCIAL SECURITY NUMBERS
INVENT A SALARY GENERATOR FOR EACH DEPT: use some base salary and
add in randomly generated offset.

PRINT OUT 10 EMPLOYEES & THEIR VALUES ONE LINE AT A TIME;
-------------------------------------------------------
*/
typedef enum {HR, SALES, RESEARCH, SOFTWARE, EXECUTIVE} DEPT;
typedef struct {
  int ID, salary;
  DEPT name;
  unsigned int SSN;
} employee;

//Include Relevant Libraries & definition of macro terms
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>
#define SALARY_MIN  3500
#define COUNT       10
#define NDEBUG

char* getDeptName(employee x)
{
  switch(x.name)
  {
    case HR: return "HR";
    case SALES: return "SALES";
    case RESEARCH: return "RESEARCH";
    case SOFTWARE: return "SOFTWARE";
    case EXECUTIVE: return "EXECUTIVE";
    default: printf("Dept not found"); return "DIE DIE DIE!";
  }
}
int generate_id()
{
  srand(time(0));
  return ((rand()+72001)%3000);
}
unsigned int generate_ssn()
{
  unsigned int num = 0;
  srand(time(0));
  num = rand() % 1000000000;
  return (num);
}

void deptsalary(employee x)
{
  int deptno = -1, offset = -1;
  offset = rand()%10;
  x.salary = offset*100 + SALARY_MIN;
  deptno = rand()%5;
  switch (deptno)
  {
    case 0: x.name = HR; break;
    case 1: x.name = SALES; break;
    case 2: x.name = RESEARCH; break;
    case 3: x.name = SOFTWARE; break;
    case 4: x.name = EXECUTIVE; break;
  }
  printf("Employee ID: %d\t Salary: $%d\t Dept: %s\t SSN: %u\t\n",
  x.ID, x.salary, getDeptName(x), x.SSN);
  return;
}
void informalTests()
{
    employee fakeone;
    int debug;
    printf("\n --------------------GENERATING SSN------------------------\n");
    fakeone.SSN = generate_ssn();
    fakeone.ID = generate_id();
    printf("SSN Test %d: %u\n", fakeone.ID, fakeone.SSN);
    printf("Program paused. Check that SSN field is not empty.\n Input any integer to continue:");
    scanf("%d",&debug);
    printf("\n -------------- GENERATING DEPT & SALARY ------------------\n");
    deptsalary(fakeone);
    printf("Program paused. Check that salary & dept is not empty.\n Input any integer to continue:");
    scanf("%d",&debug);
    printf("\n -------------- RETURNING BACK TO PROGRAM ------------------\n");
    return;
}
//MAIN CODE BODY
int main (void)
{
  informalTests();
  employee nom_roll[COUNT];
  for (int i = 0; i < COUNT; i++)
  {
    nom_roll[i].ID = generate_id();//
    nom_roll[i].SSN = generate_ssn();
    sleep(5);
  }
  for (int i = 0; i < COUNT; i++)
  {
    deptsalary(nom_roll[i]);
  }
  return (0);
}
