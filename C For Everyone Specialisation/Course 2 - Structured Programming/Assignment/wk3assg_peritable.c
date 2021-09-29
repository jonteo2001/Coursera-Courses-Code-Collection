/*
JONATHAN TEO
29 OCT 2020
peri_table.c
WEEK 3 ASSIGNMENT
------------------------ REQUIREMENT----------------------
Develop a struct that can store an atomic element,
such as Hydrogen -H -at.wt 1.008.

Now create from input at the terminal the first ten elements
in the periodic table as a linked list with this struct as data.
Then print out this information to the screen in a nicely readable
form. The struct should have three members—one stores the name of
the element, a second stores it atomic symbol, and a third stores
its weight.

No.	Atomic weight	Name	Symb.	M.P. (°C)	B.P. (°C)	Density (g/cm3)	Earth crust (%)	Discovery (year)
1	      1.008	Hydrogen	H	-259	-253	0.09	0.14	1776
2	      4.003	Helium	He	-272	-269	0.18		1895
3	      6.941	Lithium	Li	180	1347	0.53		1817
4	      9.012	Beryllium	Be	1278	2970	1085		1797
5	      10.811	Boron	B	2300	2550	2.34		1808
6	      12.011	Carbon	C	3500	4827	2.26	0.09	ancient
7	      14.007	Nitrogen	N	-210	-196	1.25		1772
8	      15.999	Oxygen	O	-218	-183	1.43	46.71	1774
9	      18.998	Fluorine	F	-220	-188	1.70	0.03	1886
10    	20.180	Neon	Ne	-249	-246	0.90		1898
---------------------------------------------------------------------
*/
typedef struct {
  char name[15];
  char symbol[4];
  double weight;
} element;

typedef struct list{
  element data;
  struct list *next;
}list;
//Include relevant libraries, and define relevant constants
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h> //strcpy
#define NDEBUG
//MANIPULATION ON THE LIST
int isempty(const list *l){return (l ==NULL);}

list* create_list(element d)
{
  printf("\n ---------- RUNNING CREATING-LIST() -------------\n");
  //list *head = malloc(sizeof(element)); WRONG!!
  list* head = malloc(sizeof(list));// CORRECT
  head -> data = d;
  head -> next = NULL;
  return head;
}
list* add_to_front(element d, list*h)
{ //FRONT OF THE LIST!! means new node becomes new head
  printf("\n ----------RUNNING ADD-TO-FRONT() -------------\n");
  list* head = create_list (d);
  head -> next = h;//this is pointing at the head.  so the new head points to the old head
  return head; // head-->next gets updated by add_to_front
}
list* array_to_list (element d[], int size)
{
  printf("\n ----------RUNNING ARRAY-TO-LIST() -------------\n");
  list* head =create_list(d[0]);//list takes the zeroth index, then 1st index
  int i;// then all the following indices of the array to be added to the list.
  for (i = 1; i < size; i++)
  {
    head = add_to_front(d[i], head); //note the head on the RHS
  }// is getting updated by the head on the LHS.
  return head; //head is a list
}
void print_element(list *h)
{
  printf("\n ----------RUNNING PRINT-ELEMENT -------------\n");
  printf("Element: %s\t Symbol: %s\t Weight: %lf\t\n", (h->data).name, (h->data).symbol, (h->data).weight);
  return;

}
void print_list(list *h, char *title)
{
  printf("\n ----------RUNNING PRINT-LIST -------------\n");
  printf("%s\n", title);//printing list title
  while (h != NULL)//when pointer does not point to null,
  {
    print_element(h); //h is the list ptr, which is currently at the head.
    h = h->next;
  }
  return;
}
void informalTests()
{
  int debug;
  printf("\n --------------------- RUNNING INFORMALTESTS()--------------\n");
  printf("\n --------------------- MAKING 2 TEST ELEMENTS ---------------\n");
  element Van;
  strcpy(Van.name, "VANADIUM");
  strcpy(Van.symbol, "V");
  Van.weight = 50.900;
  printf("Name: %s\t SYMBOL: %s\t Weight: %lf\t \n", Van.name, Van.symbol, Van.weight);
  element Cr;
  strcpy(Cr.name, "CHROMIUM");
  strcpy(Cr.symbol, "Cr");
  Cr.weight = 52.000;
  printf("Name: %s\t SYMBOL: %s\t Weight: %lf\t \n", Cr.name, Cr.symbol, Cr.weight);
  printf("Program paused. Ensure that Vanadium and Cr are printed correctly. \n Enter any integer to continue: ");
  scanf("%d", &debug);
  printf("----------------- INITIALISING ARRAY TRANSITION[2]------------- \n");
  element transition[2] = {Cr, Van};
  int i = 0;
  for (i = 0; i < 2; i++)
  {
    printf("Transition[%d] = %s\t", i, transition[i].name);
  }
  printf("\nProgram paused. Ensure that Vanadium and Cr are indexed 0 and 1 respectively. \n Enter any integer to continue: ");
  scanf("%d", &debug);
  printf(" ---------------- CHANGING ARRAY INTO LIST ------------------ \n");
  list* listptr = NULL; // listptr is a pointer to a list
  listptr = array_to_list(transition, 2);
  print_list(listptr, "The 2nd and 3rd transition elements are:");
  printf("Program paused. Ensure that Vanadium and Cr are printed correctly in the list.\n Enter any integer to continue: ");
  scanf("%d",&debug);
  printf("\n---------------- RETURNING BACK TO PROGRAM ------------------ \n");
  printf("Bye bye!\n");
  return;
}
//main code body
int main (void)
{
  informalTests();
  int debug;
  printf("\n---------- CREATING ELEMENTS & PERIODIC ARRAY ----------------\n");
  element Ne; strcpy(Ne.name, "NEON")       ; strcpy(Ne.symbol, "Ne") ; Ne.weight = 20.180;
  element Fl; strcpy(Fl.name, "FLUORINE")   ; strcpy(Fl.symbol, "F")  ; Fl.weight = 18.998;
  element Ox; strcpy(Ox.name, "OXYGEN")     ; strcpy(Ox.symbol, "O")  ; Ox.weight = 15.999;
  element Ni; strcpy(Ni.name, "NITROGEN")   ; strcpy (Ni.symbol, "N") ; Ni.weight = 14.007;
  element Cb; strcpy(Cb.name, "CARBON")     ; strcpy(Cb.symbol, "C")  ; Cb.weight = 12.011;
  element Bo; strcpy(Bo.name, "BORON")      ; strcpy(Bo.symbol, "B")  ; Bo.weight = 10.811;
  element Be; strcpy(Be.name, "BERYLLIUM")  ; strcpy(Be.symbol, "Be") ; Be.weight = 9.012 ;
  element Li; strcpy(Li.name, "LITHIUM")    ; strcpy(Li.symbol, "Li") ; Li.weight = 6.941 ;
  element He; strcpy(He.name, "HELIUM")     ; strcpy(He.symbol, "He") ; He.weight = 4.003 ;
  element Hy; strcpy(Hy.name, "HYDROGEN")   ; strcpy(Hy.symbol, "H")  ; Hy.weight = 1.008 ;

  element periodic[10] = {Ne, Fl, Ox, Ni, Cb, Bo, Be, Li, He, Hy};
  for (int i = 0; i < 10; i++)
  {
    printf("periodic[%d]--> Name: %s\t SYMBOL: %s\t Weight: %lf\t \n",
    i, periodic[i].name, periodic[i].symbol, periodic[i].weight);
  }
  printf("----------------------------------------------------------\n");
  printf("Program paused. Check that the elements are in reverse order in the array.\n Input any integer to continue: ");
  scanf("%d", &debug);
  printf("---------------------- CHANGING ARRAY INTO LINKED LIST ------------\n");
  list* listptr = NULL; // listptr is a pointer to a list
  listptr = array_to_list(periodic, 10);
  print_list(listptr, "The first 10 elements of the Periodic Table:");
  printf("\n\n");
  return 0;
}
