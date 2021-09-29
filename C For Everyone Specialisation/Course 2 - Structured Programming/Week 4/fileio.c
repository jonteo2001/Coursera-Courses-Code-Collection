/* USE OF FILE I/O
Command Line Arguments
Double space input file to output FILE2
JON TEOO 2020
*/

#include <stdio.h>
#include <stdlib.h> //exit(-1) - similar to abort

void print_file(FILE* fptr)
{
  int c;
  rewind(fptr);
  while ((c = getc(fptr))!=EOF)
  {
    putc(c,stdout);
  }
}
void double_space(FILE *ifp, FILE* ofp){
  int c;
  rewind(ifp);
  while((c=getc(ifp))!= EOF)
  {
    putc(c,ofp);
    //putchar(c);
    if (c == '\n')
    {
      putc('\n',ofp);
    }
  }
}

int main (int argc, char* argv[])
{
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
  double_space(ifp, ofp); //output file
  printf("my %s file double spaced is \n\n", argv[2]);
  print_file(ofp);
  printf("\n\n");
  fclose(ifp); fclose(ofp); return (0);
}
