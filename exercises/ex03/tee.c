#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

//int parse_flags(char[]);

/*
int parse_flags(char input[]) {
  for (int i = 0; i < strlen(input)-1; i++) {
    if (input[i] == '-') {
      if (input[i+1] == 'a') {
        return 1;
      }
      //if (input[i+1] == 'i') {
      //  return 2;
      //}
    }
  }
  return 0;
}*/

/*
int parse_tee(char input[]) {
  for (int i = 0; i < strlen(input)-3; i++) {
    if (input[i] == 't') {
      if (input[i+1] == 'e') {
        if (input[i+2] == 'e') {
          if (i+3 == strlen(input) || isspace(input[i+3])) {
            return i;
          }
        }
      }
    }
  }
  return -1;
}


int parse_name(char input[], char* name) {
  int pos = strstr(input, ".txt");
  int start_pos = -1;
  for (int i = pos-1; i>0; i--) {
    if (isspace(input[i])) {
      start_pos = i;
    }
  }
  if (start_pos == -1) {
    return 1;
  }
  memcpy(name, input + start_pos, pos + 4 - start_pos);
  return 0;
}
*/
int main (int argc, char *argv[])
{

  char input[100];
  int check_flags = 0;
  char ch;
  //
  while ((ch = getopt(argc, argv, "a")) != EOF){
    if(ch == 'a'){
      check_flags = 1;
      puts("flag found!");
      argc -=optind;
      argv += optind;
    }
  }


  puts("Reading input...");
  fgets(input, 100, stdin);


  FILE* f[argc];
  for (int i = 1; i < argc; i++){
    printf("%s\n", argv[i]);
    if (check_flags == 0) {
      f[i] = fopen(argv[i], "w");
      //puts("opened writing");
    }
    else if (check_flags == 1) {
      f[i] = fopen(argv[i], "a");
      //puts("opened appending");
    }
    if (f[i] == NULL){
      printf("Bad file input!");
      exit(1);
    }
  }
  puts("writing\n");
  //printf("%s", f[1]);
  for (int j=1; j< argc; j++) {
    //printf("%d", j);
    fprintf(f[j], "%s\n", input);
  }


  puts("written");
  return 0;
}

/*

This was difficult because I had to spend a lot of time reviewing how to open and close files, as well as using argc and argv[]. Pointers as always were a pain
and because I was short on time by the end I tried to cut as many out as possible to simplify my code. If I were to do this again, I would definitely start earlier
and spend more time thinking about how I could break it down into cleaner functions.

4. The professional implemenation is much more sophisticated, with much more selective function use, outside library calls, etc and is very dense (to the point where I
find it a little difficult to read as a less advanced programmer). The professional version also has a lot more warns and error messages that vary depending on what
the issue is that my code doesn't include.

*/
