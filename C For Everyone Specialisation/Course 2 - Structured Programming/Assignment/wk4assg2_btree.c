/*
  JONATHAN TEO
  29 OCT 2020
  WEEK 4 HONOR'S ASSIGNMENT
----------------------------------------------------------
Open and read a file of integer pairs into an array
that is created with the first integer
telling you how many to read.

So  4 9  11  4  5    would mean create an integer array size 4
and read into data[].

Write a routine that places these values into a binary tree structure.
Then walk the tree “inorder” and print these values to the screen.
Submit your work in a text file.
*/
//Declaring structs, relevant libraries and constants.
typedef struct Node {int data; struct Node* left; struct Node* right;} Node;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//DECLARING FUNC PROTOTYPES
void informalTests();
void insertIntoTree(Node ** tree, int val);
Node* search(Node ** tree, int val );
void delTree(Node * tree);
void print_preorder(Node*tree);
void print_inorder(Node *tree);
void print_postorder(Node *tree);
int getSize (FILE* ptr);
int* data_array(int* ptr, FILE*fp, int size);

//DRIVER CODE
int main (int argc, char* argv[])
{
  informalTests();
  if (argc != 2) {printf("Need executable input file!");}
  FILE* ifp;
  int size, i;
  Node* root = NULL, *temp;

  ifp = fopen(argv[1], "r");
  size = getSize(ifp);
  int data[size];//initialise variable data here
  int* arr_ptr = &data[0];
  arr_ptr = data_array (arr_ptr, ifp, size);
  //Insert data elements into Tree
  for (i = 0; i < size; i++)
  {
    insertIntoTree(&root, data[i]);
  }
  print_inorder(root);
  return 0;
}
//Declaring ALL functions
void informalTests()
{
  int debug;
  printf("\n---------------- RUNNING INFORMAL TESTS ------------- \n");
  FILE *fp, *out;
  fp = fopen("sample_data.txt", "r");
  printf("\n---------------- GETTING THE SIZE OF ARRAY ---------- \n");
  int size = getSize(fp);
  printf("Size should be equal to 4. \n Array Size: %d. \n Enter any integer to continue:", size);
  scanf("%d", &debug);
  int data[size];
  int *arr_ptr = &data[0];
  printf("\n --------------- READ FILE INTO ARRAY -------------- \n");
  data_array(arr_ptr, fp, size);
  printf("Printing Array:");
  for (int i = 1; i < size; i++)
  {
    printf("data[%d]= %d\n", i, data[i]);
  }
  printf("\n------------------------------------------\n");
  printf("\n Program Paused. Check that output is 9 	11 	12 	15.\n Enter any integer to continue:");
  scanf("%d", &debug);
  printf("\n --------------- TESTING BTREE FUNCTIONALITY ------------ \n");
  Node* root = NULL, *temp;
  for (int i = 0; i < size; i++)
  {
    insertIntoTree(&root, data[i]);
  }
  printf("\n------- INORDER TRAVERSAL --------\n");
  print_inorder(root);
  printf("\n ---------- PREORDER TRAVERSAL --------- \n");
  print_preorder(root);
  printf("\n --------- POSTORDER TRAVERSAL --------- \n");
  print_postorder(root);
  printf("\n Program Paused. Check that output is \n");
  printf("Inorder: 9, 11, 12, 15; \n Preorder:11, 9, 12, 15, \n PostOrder: 9, 15, 12, 11\n");
  printf("Enter any integer to continue: ");
  scanf("%d", &debug);
  printf("\n --------- ADDING NODE TO BTREE ------- \n");
  insertIntoTree(&root, 13);
  insertIntoTree(&root, 13);
  print_inorder(root);
  printf("\n Program Paused. Make sure the 2nd insertion into the btree has failed.\n Enter any integer to continue:");
  scanf("%d", &debug);
  printf("\n --------- SEARCHING BTREE FOR A NODE ------ \n");

  Node * value = search(&root, 9);
  printf("Value of Node: %d", value->data);
  printf("\n Program Paused. Check that the node of value 9 has been found. \n Enter any integer to continue:");
  scanf("%d", &debug);

  printf("\n -------- DELETING BTREE ---------- \n");
  delTree(root);
  printf("\n Program Paused.\n Enter any integer to continue:");
  scanf("%d", &debug);
  printf("-------------- RETURNING BACK TO PROGRAM ------------ \n");
  return;
}

void insertIntoTree(Node ** tree, int val)//Note this is the pointer TO A POINTER
//to a node in the tree
{
  Node * temp = NULL;//pointer to a node
  if (!(*tree))
  {//Create the tree!
    temp = (Node*)malloc(sizeof(Node));
    temp->left = temp->right = NULL;
    temp->data = val;
    *tree = temp; return;
  }
  else{
    if(val < (*tree)->data) {insertIntoTree(&((*tree)->left), val);} //Recursive
    else if(val > (*tree)->data) {insertIntoTree(&((*tree)->right), val);}//Recursive
    else {printf("Data cannot be inserted into btree!");}// {val == (*tree)->data}
    return;
  }
}
Node* search(Node ** tree, int val )
{
  if (!(*tree)) {return NULL;}
  else{
    if (val == (*tree)->data){return (*tree);}
    else if(val < (*tree)->data){return search(&((*tree)->left), val);}
    else {return search(&((*tree)->right), val);}
  }
}
void delTree(Node * tree)
{
  if(tree)
  {
    delTree(tree->left);
    delTree(tree->right);
    free(tree);
  }
}
void print_preorder(Node*tree)
{
  if (tree)
  {
    printf("%d\t", tree->data);
    print_preorder(tree->left);
    print_preorder(tree->right);
  }
}
void print_inorder(Node *tree)
{
  if (tree)
  {
    print_inorder(tree->left);
    printf("%d\t", tree->data);
    print_inorder(tree->right);
  }
}
void print_postorder(Node *tree)
{
  if(tree)
  {
    print_postorder(tree->left);
    print_postorder(tree->right);
    printf("%d\t", tree->data);
  }
}
//end of functionality for Btree, now functionality for File I/O
int getSize (FILE* ptr)
{
  int size;
  rewind(ptr);
  fscanf(ptr, "%d", &size);
  return (size);
}
int* data_array(int* ptr, FILE*fp, int size)
{
  for (int i = 0; i<size; i++)
  {
    fscanf(fp, "%d\t", ptr+i);
  }
  return ptr;
}
