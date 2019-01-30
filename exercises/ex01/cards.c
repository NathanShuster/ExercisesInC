/*
Card Counting program in C
Nathan Shuster
A modified version of a program from HeadFirstC that keeps a running card count
from a series of cards input by the user.
*/

#include <stdio.h>
#include <stdlib.h>

int countCard(char[3]);
void checkInput(int, char[3]);


/* Prompts the user to enter a series of cards to feed into counting program.
  After every input, the program prints the current count and any error messages
  if the user input is incorrectly formatted.
*/
int main()
{
  char card_name[3];
  int count = 0;
  do {
    puts("Enter card name (2, 3, 4...J, Q, K, A). Type 'X' to end program.");
    scanf("%2s", card_name);
    count += countCard(card_name);
    printf("Current count: %i\n", count);
  } while (card_name[0] != 'X');
  return 0;
}

/* Evaluates a user's card input to generate a count value (-1, 0, or 1).
      card_name: user input, truncated to first two characters
*/
int countCard(char card_name[3]) {
  int val = 0;
  switch(card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      return 1;
    case 'A':
    case 'X':
      return 0;
    default:
      val = atoi(card_name);
      if ((val > 2) && (val < 7)) {
        return -1;
      }
      checkInput(val, card_name);
      return 0;
    }
}

/* Checks user input for errors and gives feedback if necessary.
    card_name: card input by user, truncated to first two characters
    val: integer value of the card, if the card_name is a number
*/
void checkInput(int val, char card_name[3]) {
  if (card_name[0] == 'j' || card_name[0] == 'q'
   || card_name[0] == 'k' || card_name[0] == 'a') {
    puts("\nPlease capitalize face cards.\n");
  }
  else if (val < 1 || val > 10) {
    puts("\nInvalid Input.\n");
  }
}
