// Michael Said
// Liam May
// COP 3402
// Spring 2020

// This program is an implementation of a lexical analyzer for PL/0
// [ ] means an optional item,
// { } means repeat 0 or more times.
// Terminal symbols are enclosed in quote marks.
// A period is used to indicate the end of the definition of a syntactic class.
// Comments and invisible characters are ignored

#include <stdio.h>

#define MAX_IDENT_LENGTH 11
#define MAX_NUM_LENGTH 5
#define MAX_CODE_LENGTH 550

// Defines token types and their initial values
typedef enum {
nulsym = 1, identsym = 2, numbersym = 3, plussym = 4, minussym = 5, multsym = 6,
slashsym = 7, oddsym = 8, eqsym = 9, neqsym = 10, lessym = 11, leqsym = 12,
gtrsym = 13, geqsym = 14, lparentsym = 15, rparentsym = 16, commasym = 17,
semicolonsym = 18, periodsym = 19, becomessym = 20, beginsym = 21, endsym = 22,
ifsym = 23, thensym = 24, whilesym = 25, dosym = 26, callsym = 27, constsym = 28,
varsym = 29, procsym = 30, writesym = 31, readsym = 32 , elsesym = 33
} token_type;

// Table of reserved word names
char reserved[14][9] = { "const", "var", "procedure", "call", "begin", "end",
                         "if", "then", "else", "while", "do", "read", "write",
                         "odd" };

// Table of special symbols
char symbols[13] = { '+', '-', '*', '/', '(', ')', '=', ',', '.', '<', '>', ';',
                     ':' };

int main(int argc, char **argv)
{
  // printf("Reserved words: \n");
  // for (int i = 0; i < 14; i++)
  // {
  //   printf("%s\n", reserved[i]);
  // }
  char source[MAX_CODE_LENGTH];
  FILE *fp = fopen(argv[1], "r");
  int i = 0;

  while (!feof(fp))
  {
    fscanf(fp, "%c", &source[i++]);
    
    //i think we should print the outcome here
    //fgets(source, MAX_CODE_LENGTH, fp);
    //puts(source);
    //just saw the printf below so nevermind but ill leave this in the comments 
  }
  printf("Source Program:\n%s\n", source);

  return 0;
}
