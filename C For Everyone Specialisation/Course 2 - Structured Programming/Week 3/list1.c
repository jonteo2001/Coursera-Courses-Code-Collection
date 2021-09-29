/*ADT LISTS
OCT 2020 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct list{int data; struct list *next;} list;
/* in a struc of type list, this list has multiple characteristics which include
data and a next pointer to a SIMILAR LIST STRUCTURE.*/
int is_empty(const list *l){return (l == NULL);} // checks if list is empty
void print_list(list *h, char *title) //
{
  printf("%s\n", title);//printing list tile
  while (h != NULL)//when pointer does not point to null,
  {
    printf("%d: ", h->data); // h point to data.
    h = h->next;
  }
}
int main()
{
  list list_of_int; // make a new list element
  list* head = NULL; // make a pointer to a list
  head = malloc(sizeof(list));
  printf("sizeof(list) = %lu \n", sizeof(list)); //unsigned long
  head -> data = 5;
  head -> next = NULL;
  print_list(head, "single element list");
  printf("\n\n");
  return 0;
}
