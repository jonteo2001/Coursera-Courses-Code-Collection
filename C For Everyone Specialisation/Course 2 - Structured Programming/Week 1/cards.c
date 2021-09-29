/*
JONATHAN TEO
29 OCTOBER 2020
cards.c

Use a struct to define a card as an enumerated member
that is its suit value and a short that is its pips value.

Write a function that randomly shuffles the deck.

Submit your work as a text file.

Then deal out 7 card hands and evaluate the probability that
    - a hand has no pair,
    - one pair,
    - 3 two pair,
    - three of a kind,
    - full house, and
    - 4 of a kind.

This is a Monte Carlo method to get an approximation to these probabilities.
Use at least 1 million randomly generated hands.

You can check against probabilities found in a standard table.
Hand	Combinations	Probabilities
Royal flush	4324	0.00003232
Straight flush	37260	0.00027851
Four of a kind	224848	0.00168067
Full house	3473184	0.02596102
Flush	4047644	0.03025494
Straight	6180020	0.04619382
Three of a kind	6461620	0.04829870
Two pair	31433400	0.23495536
Pair	58627800	0.43822546
Ace high or less	23294460	0.17411920
Total	133784560	1.00000000
-----------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Relevant libraries
typedef enum suit { HEARTS, SPADES, CLUBS, DIAMONDS } suit;
typedef struct { suit name; short value;} card;


//Declaration of Function prototypes
void informalTests();
card MakeNewDeck(card x, int val, int suittype);
int checkFourKind(card x[], int size);
int checkThreeKind(card x[], int size);
int checkOnePair(card x[], int size);
int checkTwoPairs(card x[], int size);
int checkFullHouse(card x[], int size);
card* shuffle(card x[], int n);
char* printsuit(suit name);
void printcard(card x);

//MAIN DRIVER CODE
int main (void)
{
  //informalTests();
  long double op=0.00,tp =0.00 ,tk = 0.00,fh =0.00 ,fk = 0.00; //variables needed for operation
  int i, j,k; //iterative variables
  int debug;
  suit z;
  long double p_op = 0.00, p_tp = 0.00, p_tk = 0.00, p_fh = 0.00 , p_fk = 0.00;//variables for probability
  card empty_deck[52], new_deck[52], hand[7];//variables to show card handling
  card * cardptr = &new_deck[0];
  //use empty deck for deck of no named cards, new_deck will be the one that
  //is storing all unique data.
  for (k = 0; k <52; k++){
        if (k/ 14 == 0){new_deck[k].name = HEARTS; new_deck[k].value = (k%13)+1;}
        else if(k / 14 == 1){new_deck[k].name = SPADES; new_deck[k].value = (k%13)+1;}
        else if(k / 14 == 2){new_deck[k].name = CLUBS; new_deck[k].value = (k%13)+1;}
        else {new_deck[k].name = DIAMONDS; new_deck[k].value = (k%13)+1;}
  }//end outermost for
  for (k = 0; k < 52; k++){
    printcard(new_deck[k]);
    printf("\t");
  }
  printf("\n Program Paused. Check that a deck of cards is printed successfully. \n Enter any integer to continue:");
  scanf("%d", &debug);
  long int count = 0;
  for (i = 0; i < 10000000; i++){
    cardptr = shuffle(new_deck, 52);
    //for (k = 0; k < 52; k++) {printcard(new_deck[k]);}
    //printf("\n Program Paused. Check that cards are shuffled properly. \n Enter any integer to continue:");
    //scanf("%d", &debug);
    for (k = 0; k < 7; k++) {hand[k] = new_deck[k];
      //printcard(new_deck[k]);
    }
    //printf("\n Program Paused. Check that the hand is the first 7 cards of the shuffled deck. \n Enter any integer to continue:");
    //scanf("%d", &debug);
    if(checkFourKind(hand, 7)==1) {fk = fk+1;}
    else if(checkFullHouse(hand, 7) == 1) {fh = fh+1;}
    else if(checkThreeKind(hand, 7) == 1){ tk = tk+1;}
    else if(checkTwoPairs(hand, 7) == 1) { tp = tp+1;}
    else if(checkOnePair(hand,7) == 1) {op = op+1;}
    else {printf(".....\t");}
    count = count + 1;
  }//endfor
  p_op = op/count; p_tp = tp/count; p_tk = tk/count;
  p_fh = fh/count; p_fk = fk/count;
  printf("-------------Total Games Report ---------- \n");
  printf("Total Games played: %ld\n",count);
  printf("Probability of one pair: %Lf\n", p_op);
  printf("Probability of two pairs: %Lf\n",p_tp);
  printf("Probability of three kind: %Lf\n",p_tk);
  printf("Probability of full house: %Lf\n",p_fh);
  printf("Probability of four kind: %Lf\n",p_fk);
  return 0;
}
//-- END DRIVER CODE, FUNCTION DEFINITIONS BELOW--
void informalTests()
{
  int debug;
  //card hand1[7], hand2[5];//variables to show card handling
  printf("\n------- RUNNING FUNCTION INFORMAL TESTS()---------\n");
  printf("\n------- MAKING RANDOM CARD HAND --------- \n");
  //Making a full house hand
  card hearts5, clubs5, diamonds5, spades5, hearts13, diamonds13, spades6;
  hearts5.name    = HEARTS  ; hearts5.value   = 5 ;
  clubs5.name     = CLUBS   ; clubs5.value    = 5 ;
  diamonds5.name  = DIAMONDS; diamonds5.value = 5 ;
  spades5.name    = SPADES  ; spades5.value   = 5 ;
  hearts13.name   = HEARTS  ; hearts13.value  = 13;
  diamonds13.name = DIAMONDS; diamonds13.value= 13;
  spades6.name    = SPADES  ; spades6.value   = 6 ;
  printf("\n--------TESTING PRINTCARD FUNCTION------------- \n");
  printcard(hearts5);
  printcard(diamonds13);
  printf("\n Program Paused. Check that 5 of Hearts & 13 of Diamonds has been printed.\n Enter any integer to continue: ");
  scanf("%d", &debug);
  printf("\n ------- CREATING CARD HAND ----------------- \n");
  card hand1[7] = {hearts5, clubs5, diamonds5, spades5, hearts13, diamonds13, spades6};
  card hand2[5] = {hearts5, hearts13, spades6, clubs5, diamonds13};
  printf("\n ------- PROGRAM STEP 2: TESTING EACH FUNCTION SEPARATELY---------- \n");
  printf("\n ------- FUNCTION CHECK ONE PAIR------------ \n");
  printf("OUTPUT: val1 = %d, val2 = %d\n",checkOnePair(hand1, 7), checkOnePair(hand2, 5));
  printf("\n Program Paused. Check that output is 1 and 1 respectively. \n Enter any integer to continue: ");
  scanf("%d", &debug);
  printf("\n ------- FUNCTION CHECK TWO PAIR------------ \n");
  printf("OUTPUT: val1 = %d, val2 = %d\n",checkTwoPairs(hand1, 7), checkTwoPairs(hand2, 5));
  printf("\n Program Paused. Check that output is 1 and 1 respectively. \n Enter any integer to continue: ");
  scanf("%d", &debug);
  printf("\n ------- FUNCTION CHECK THREE KIND------------ \n");
  printf("OUTPUT: val1 = %d, val2 = %d\n",checkThreeKind(hand1, 7), checkThreeKind(hand2, 5));
  printf("\n Program Paused. Check that output is 1 and 0 respectively. \n Enter any integer to continue: ");
  scanf("%d", &debug);
  printf("\n ------- FUNCTION CHECK FOUR KIND------------ \n");
  printf("OUTPUT: val1 = %d, val2 = %d\n",checkFourKind(hand1, 7), checkFourKind(hand2, 5));
  printf("\n Program Paused. Check that output is 1 and 0 respectively. \n Enter any integer to continue: ");
  scanf("%d", &debug);
  printf("\n ------- FUNCTION CHECK FULL HOUSE------------ \n");
  printf("OUTPUT: val1 = %d, val2 = %d\n",checkFullHouse(hand1, 7), checkFullHouse(hand2, 5));
  printf("\n Program Paused. Check that output is 1 and 0 respectively. \n Enter any integer to continue: ");
  scanf("%d", &debug);
  printf("\n ------- RETURNING BACK TO PROGRAM ----------- \n");
  return;
}
card MakeNewDeck(card x, int val, int suittype)
{
  switch (suittype)
  {
    case 1: x.name = SPADES; break;
    case 2: x.name = CLUBS; break;
    case 3: x.name = DIAMONDS; break;
    case 4: x.name = HEARTS; break; //end else
  }
  x.value = val;
  return (x);
}
int checkFourKind(card x[], int size){
  int i,j,k,l;
  for (i = 0; i<size; i++){
    for (j = i+1; j < size; j++){
      for (k = j+1; k< size; k++){
        for (l = k+1; l < size; l++){
          if (x[i].value == x[j].value == x[k].value == x[l].value)
              {return (1);}
        }//end for l
      }//end for k
    }//end for j
  }//end for i
  return 0;
}//end func
int checkThreeKind(card x[], int size){
  int i,j,k;
  if (checkOnePair(x, size) == 1){
    for (i = 0; i < size; i++){
      for (j = i+1; j < size; j++){
        if (x[i].value != x[j].value){continue;}
        else{
          for (k = j+1; k < size; k++){
            if (x[k].value == x[j].value)
            {
              return(1);
            }
          }//end for k
        }//end else
      }//end for j
    }//end for i
    return (0);
  }//end if checkone pair
  else {return 0;}
}//end func
int checkOnePair(card x[], int size){
  int i,j;
  for (i = 0 ; i < size; i++){
    for (j = i+1; j < size; j++){
      if (x[i].value == x[j].value){return 1;}
    }//end for j
  }//end for i
  return 0;
}//end func
int checkTwoPairs(card x[], int size){
  int i,j,k,l;
  if (checkOnePair(x, size)==1)
  {
    for (i = 0; i< size; i++){
      for (j= i+1; j < size; j++){
        if (x[i].value != x[j].value){continue;}
        else{//x[i].value == x[j].value
          for (k=0; k < size; k++){ //k should start from 0 in case some cards
                                    //were skipped in the process*
            for (l = k+1; l <size; l++){
              if (x[k].value == x[l].value && x[k].value != x[j].value){return 1;}
            }//end for l
          }// end for k
        }//end else
      }//end for j
    }// end for i
    return (0);
  }//end if check one pair
  else {return (0);}
}//end func
int checkFullHouse(card x[], int size){
  if (checkThreeKind(x,size) == 1){
    int i,j,k,l,m;
    for (i = 0; i < size; i++){
        for (j = i+1; j < size; j++){
          if (x[i].value != x[j].value){continue;}
          else{
            for (k = j+1; k < size; k++){
              if (x[k].value != x[j].value){continue;}
              else{
                for (l = 0; l < size; l++){
                  for (m = l+1; m < size; m++){
                    if (x[l].value == x[m].value && x[l].value != x[k].value) {return (1);}
                    else {continue;}
                  }//end for m
                }//end for l
              }//end else
            }//end for k
          }//end else
        }//end for j
    }//end for i
  }//end if check three kind
  return 0;
}//end func
card* shuffle(card x[], int n)
{
    srand(time (0)); int i; card temp;
    for (i = 0; i < n; i++)
    {
      int r = i + (rand()%(52-i));
      temp = x[i]; x[i]= x[r]; x[r] = temp;
    }
    card* cardptr = &(x[0]);
    return cardptr;
}
char* printsuit(suit name)
{
  switch (name)
  {
    case CLUBS: return "CLUBS";
    case HEARTS: return "HEARTS";
    case SPADES: return "SPADES";
    case DIAMONDS: return "DIAMONDS";
  }
}
void printcard(card x)
{
    printf("%d %s\t", x.value, printsuit(x.name)); return;
}
