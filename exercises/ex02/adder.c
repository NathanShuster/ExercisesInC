#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int read_input(int);

/* Reads input until an error or EOF is returned, while storing results in int numbers[].
  Sums values of numbers[] and prints out result at end.
*/
int main()
{
  int numbers[11];
  int num_count = 0;
  int val = 0;
  for (;;) {
    val = read_input(num_count);
    if (val == -99999) {
      break;
    }
    numbers[num_count] = val;
    num_count++;
  }
  int sum = 0;
  for (int i = 0; i < num_count; i++) {
    sum += numbers[i];
  }
  printf("Your sum is %d\n", sum);
  return 0;
}

/*
Prompts the user for an input, evaluates it for validity and if valid returns it as an int

num_count is the number of inputs read so far.
Max 10 inputs
Max 10 digits per input
If can't parse, too large, or too many inputs, then will return error and sum previous
*/
int read_input(int num_count) {
  int val = 0;
  puts("Enter number. Enter command + D to end input:");
  char num[15];
  val = scanf("%12s", num);
  if(val == EOF) {
    puts("Detected EOF");
    return -99999;
  }
  if (strlen(num) > 10) {
    puts("Error: too large of a number! Summing up previous numbers...");
    return -99999;
  }
  int numval = atoi(num);
  if (numval == 0) {
    puts("Invalid input. Summing up previous numbers...");
    return -99999;

  }
  if (num_count < 10) {
    return numval;
  }
  else {
    puts("Error: max 10 inputs. Press Ctrl + D to finish sequence");
  }

}
