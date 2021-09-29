/*
JONATHAN TEO
29 OCT 2020
doublelist.c
---------------------------------------
Modify the singly linked list to be a doubly linked list.
Now write a routine that removes all duplicate data in the
doubly linked list. The data will be integers generated
at random from [0,49]. Initially have a list of 200 elements.

Now do this in one of two ways.
Sort the list by its data field.
Remove adjacent elements of the sorted list with the same value.
Or, take the first element—search the remainder of the list
for elements with the same data and remove them.
Then take the second element and do the same.
Repeat until only one element is left.
*/

typedef struct Node {int data; struct Node* next; struct Node* prev;} Node;
typedef struct {Node* head; Node* tail;} List;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>//Relevant Libraries
//DECLARING FUNCTION PROTOTYPES
void informalTests();
void initList(List* ptr);
Node* createNode (int data);
void addAtTail(List* ptr, int data);
int delFromTail(List* listptr);
void addAtHead(List* listptr, int data);
int delFromHead(List* listptr);
void printList(List* listptr);
void deleteFromMid(List* listptr);
int deleterepeats(List* listptr);
//-----------DRIVER CODE------------
int main (void)
{
  informalTests();
  List* listptr;
  int data = 0, i, count;
  listptr = (List*)malloc (sizeof(List));
  initList(listptr); //initialise list
  for (i = 0; i < 200; i++)
  {
    srand(time(0));
    data = (rand() + i*i) % 50;//mod 50 so integers fall into the range of 0-49.
    addAtTail(listptr, data);
  }
  printList(listptr);
  count = deleterepeats(listptr);
  printList(listptr);
  printf("Count = %d", count);
  return (0);
}
//--------- FUNCTION DEFINTIIONS BELOW
void informalTests()
{
  int debug;
  printf("\n ------- RUNNING FUNCTION INFORMALTESTS () ---------- \n");
  printf("\n ------- CREATING MINI LIST OF 3 NODES ---------- \n");
  int data[3] = {1,2,3};
  List* minilist;
  minilist = (List*) malloc(sizeof(List));
  printf("\n ------- INITIALISING LIST --------------- \n");
  printList(minilist);
  printf("\n Program Paused. Check that list is empty - if it is, Printlist function works when list is empty.\n Enter any integer to continue: ");
  scanf("%d", &debug);
  printf("\n ------- RUNNING FUNCTION addAtTail -------- \n");
  addAtTail(minilist, data[1]);
  printList(minilist);
  printf("\n Program Paused. Check that output:  2.\n Enter any integer to continue: ");
  scanf("%d", &debug);
  printf("\n ------- RUNNING FUNCTION addAtTail -------- \n");
  addAtTail(minilist, data[2]);
  printList(minilist);
  printf("\n Program Paused. Check that output:  2 ---> 3.\n Enter any integer to continue: ");
  scanf("%d", &debug);
  printf("\n ------- RUNNING FUNCTION addAtHead -------- \n");
  addAtTail(minilist, data[1]);
  printList(minilist);
  printf("\n Program Paused. Check that output:  1 ---> 2 ---> 3. \n Enter any integer to continue: ");
  scanf("%d", &debug);
  printf("\n ------- RUNNING FUNCTION deleteFromMid -------- \n");
  printf("Value deleted from list:%d", deleteFromMid(minilist));
  printList(minilist);
  printf("\n Program Paused. Check that output:  1 ---> 3 \n. Enter any integer to continue: ");
  scanf("%d", &debug);
  printf("\n ------- RUNNING FUNCTION delFromTail -------- \n");
  printf("Integer deleted: %d", delFromTail(minilist));
  printf("\n Program Paused. Check that output:  3.\n Enter any integer to continue: ");
  scanf("%d", &debug);
  addAtTail(minilist, 2); addAtTail(minilist, 3);
  printf("\n ------- RUNNING FUNCTION delFromHead -------- \n");
  printf("Integer deleted: %d\t", delFromHead(minilist));
  printf("\n Program Paused. Check that output:  1. \n Enter any integer to continue: ");
  scanf("%d", &debug);
  printf("\n ------- RUNNING FUNCTION delFromTail -------- \n");
printf("Integer deleted: %d", delFromTail(minilist);
  printf("\n Program Paused. Check that output:  1.\n Enter any integer to continue: ");
  scanf("%d", &debug);
  addAtHead(minilist, 1);printList(minilist);
  printf("\n Program Paused. Check that output:  1 ---> 2 ---> 3.\n Enter any integer to continue: ");
  scanf("%d", &debug);
  addAtHead(minilist, 2); addAtHead(minilist, 3);
  printList(minilist);
  printf("# of nodes deleted: %d\n", deleterepeats(minilist));
  printList(minilist);
  printf("\n Program Paused. Check for the following outputs:\n2 nodes deleted. \nList: 1 ---> 2 ---> 3.\n Enter any integer to continue: ");
  printf("\n -------- RETURNING BACK TO PROGRAM ---------- \n");
  return;
}
void initList(List* ptr){
  ptr -> head = NULL;
  ptr -> tail = NULL; return;
}
Node* createNode (int data){
  Node* newNode;//ptr to new Node
  newNode = (Node*)malloc (sizeof(Node));
  newNode -> data = data;
  newNode -> next = NULL;
  newNode->prev = NULL;
  return (newNode);
}
void addAtTail(List* ptr, int data)
{
  Node* newtail, *oldtail;
  newTail = createNode(data);
  //Check if list is empty.
  if (ptr->head == NULL) { ptr->head = newTail; ptr->tail = newTail;}
  else
  {
    ptr->tail = oldtail;
    newtail->prev = oldtail;
    oldtail->next = newtail;
    //newtail->next = NULL - already set by create node
    listptr->tail = listptr->tail->next;//to update the list tail
  } return;
}
int delFromTail(List* listptr)
{
  Node *temp, *prevNode; //temp is the iterative variable
  int value; //value to be returned.
  if (listptr->tail == NULL) {printf("List is empty! \n"); return(-1);}
  else
  {
    temp = listptr->head; //initialised temp
    while (temp->next ! = listptr->tail){temp = temp->next;}
    value = listptr->tail->item;
    listptr->tail = temp;
    listptr->tail->next = NULL;
    listptr->prev = prevNode;
    listptr->tail = prevNode; //update list ptr
    prevNode->next = NULL;
  }
  return (value);
}
void addAtHead(List* listptr, int data)
{
  Node *newHead, *oldHead;
  newHead = createNode(data);
  if (listptr->head == NULL){printf("List is empty! \n"); return;}
  else
  {
    listptr->head = oldHead;
    newHead->next = oldHead;
    oldHead->prev = newHead;
    //newHead->prev = NULL; //already set
  } return;
}
int delFromHead(List* listptr)
{
  int value = 0; Node* newHead, *oldHead;
  if (listptr -> head != NULL){printf("You're mad! List is empty!\n"); return (-1);}
  else
  {
    listptr->head = oldHead;
    listptr->head->next = newHead;
    oldHead->next = NULL;
    newHead->prev = NULL;
    listptr->head = newHead;//update listptr
    value = oldHead->data;//get deleted value
  }
  return (value);
}
void printList(List* listptr)
{
  Node* nprint;
  if (listptr -> head != NULL){printf("List is empty! Give up! \n"); return;}
  else
  {
    listptr->head = nprint;
    while (nprint != NULL)
    {
      printf("%d", nprint->item);
      nprint = nprint->next;
    }
    if (nprint != NULL) {printf(" --> ");}
  }
  return;
}
void deleteFromMid(List* listptr)
{
  Node *nextNode, *prevNode, *dnode, *temp;
  int value;
  if (listptr->head == NULL){printf("list is empty! \n"); return;}
  else
  {
    temp = listptr->head;
    while (temp->next != listptr->next){temp = temp->next;}
    temp = dnode; //node to be deleted
    value = dnode->data;
    nextNode = dnode->next;
    prevNode = dnode->prev;
    //for the deleted node
    dnode->prev = NULL; dnode->next = NULL;
    //for the prev node and the node after
    nextNode->next = nextNode;
    nextNode->prev = prevNode;
    printf("Node deleted: %d", value);
  } //end else
  return;
}
int deleterepeats(list* listptr)
{
  Node *searchNode, *excessNode, *temp, *iter;
  int value = -1;
  int counter = 0;
  if (listptr->head == NULL){printf("List doesn't exist lol\n "); return (-1);}
  else{
    temp  = listptr->head;
    while (temp -> next != NULL)
    {
      value = temp->data;
      while (temp->next ! = NULL)
      {
        if (temp->next->data == value)
        {
          excessNode = temp->next;
          deleteFromMid(excessNode);
          counter = counter+1;
        }
        else{temp = temp->next;}
      }//end while
    }//end else
  }//end if
  return (counter);
}//end func
