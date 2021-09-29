/*ADT LISTS FULL LISTS
OCT 2020 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list{int data; struct list *next;} list;
/* in a struc of type list, this list has multiple characteristics which include
data and a next pointer to a SIMILAR LIST STRUCTURE.*/
int is_empty(const list *l){return (l == NULL);} // checks if list is empty

list* create_list(int d)
{
  list* head = malloc(sizeof(list));
  head -> data = d;
  head -> next = NULL;
  return head;
}
list* add_to_front(int d, list*h){ //FRONT OF THE LIST!! means new node becomes new head
  list* head = create_list (d);
  head -> next = h;//this is pointing at the head.  so the new head points to the old head
  return head; // head-->next gets updated by add_to_front
}
list* array_to_list (int d[], int size){
  list* head =create_list(d[0]);//list takes the zeroth index, then 1st index
  int i;// then all the following indices of the array to be added to the list.
  for (i = 1; i < size; i++)
  {
    head = add_to_front(d[i], head); //note the head on the RHS
  }// is getting updated by the head on the LHS.
  return head; //head is a list
}
void print_list(list *h, char *title)
{
  printf("%s\n", title);//printing list title
  while (h != NULL)//when pointer does not point to null,
  {
    printf("%d:-> ", h->data); // h point to data.
    h = h->next;
  }
}
int main()
{
  list list_of_int; // make a new list element wait what's the purpose of this line??
  list* listptr = NULL; // head is a pointer to a list
  int data[6] = {1,2,3,4,5,6};
  listptr = array_to_list(data, 6);
  print_list(listptr, "single element list");
  printf("\n\n");
  return 0;
}
