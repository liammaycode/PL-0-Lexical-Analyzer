// Michael Said
// Liam May
// COP 3402
// Spring 2020

#include <stdio.h>
#include <string.h>
#include <stdbool.h> // for booleans
#include <ctype.h> // for isalpha/isdigit
#include <stdlib.h> // for malloc

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

typedef struct lexemes
{
  token_type type;
  char *lexeme;
}lexeme;

lexeme *createLexeme(token_type t, char *str)
{
	// calloc() initializes the 'left' and 'right' pointers to NULL for us.
	lexeme *l = malloc(1 * sizeof(lexeme));
	l->type = t;
  l->lexeme = str;
	return l;
}

void parseSource(char *src, char *lexemeList);
void trim(char *str);
bool isIdentifier(char *str);
bool isNumber(char *str);

// gets rid of comments by overwriting all character within the comments and the
// comment markers themselves
void trim(char *str)
{
  int lp = 0, rp, diff, i, len = strlen(str);
  while (str[lp] != '\0')
  {
    if (str[lp] == '/' && str[lp + 1] == '*')
    {
      rp = lp + 2;
      while (str[rp] != '*' && str[rp + 1] != '/')
      {
        rp++;
      }
      rp += 2;

      diff = rp - lp;
      for (i = 0; i < diff; i++)
      {
        str[lp + i] = str[rp + i + 1];
      }
    }
    lp++;
  }
  // printf("\nTrimmed input:\n%s\n", str);
}

// checks for errors and prints tokenized output
void parseSource(char *src, char *lexemeList)
{
  // Table of special symbols
  char symbols[13] = { '+', '-', '*', '/', '(', ')', '=', ',', '.', '<', '>', ';',
                       ':' };

  while ()
}

// returns true if the string is a valid identifier and false otherwise
bool isIdentifier(char *str)
{
  int i = 1, len = strlen(str);
  if (!isalpha(str[0]) || len > MAX_IDENT_LENGTH)
  {
    return false;
  }

  for (i = 1; i < len; i++)
  {
    if (!isalpha(str[i]) || !isdigit(str[i]))
    {
      return false;
    }
  }

  return true;
}

// return true if string is a valid number and false otherwise
bool isNumber(char *str)
{
  int i, len = strlen(str);

  if (len > MAX_NUM_LENGTH)
  {
    return false;
  }
  for (i = 0; i < len; i++)
  {
    if (!isdigit(str[i]))
    {
      return false;
    }
  }
  return true;
}

// return true if the string is a reserved keyword and false otherwise
bool isReserved(char *str)
{
  // Table of reserved word names
  char reserved[14][9] = { "const", "var", "procedure", "call", "begin", "end",
                           "if", "then", "else", "while", "do", "read", "write",
                           "odd" };
  if (str[0] == 'b')
  {
    if (strcmp(reserved[4], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'c')
  {
    if (strcmp(reserved[0], str) == 0)
    {
      return true;
    }
    else if (strcmp(reserved[3], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'd')
  {
    if (strcmp(reserved[10], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'e')
  {
    if (strcmp(reserved[5], str) == 0)
    {
      return true;
    }
    else if (strcmp(reserved[8], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'i')
  {
    if (strcmp(reserved[6], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'o')
  {
    if (strcmp(reserved[13], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'p')
  {
    if (strcmp(reserved[2], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'r')
  {
    if (strcmp(reserved[11], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 't')
  {
    if (strcmp(reserved[7], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'v')
  {
    if (strcmp(reserved[1], str) == 0)
    {
      return true;
    }
  }
  if (str[0] == 'w')
  {
    if (strcmp(reserved[9], str) == 0)
    {
      return true;
    }
    else if (strcmp(reserved[12], str) == 0)
    {
      return true;
    }
  }
  return false;
}

int main(int argc, char **argv)
{
  // printf("Reserved words: \n");
  // for (int i = 0; i < 14; i++)
  // {
  //   printf("%s\n", reserved[i]);
  // }
  char source[MAX_CODE_LENGTH];
  lexeme list[MAX_CODE_LENGTH];
  FILE *fp = fopen(argv[1], "r");
  int i = 0;

  // collecting source program from file
  while (!feof(fp))
  {
    fscanf(fp, "%c", &source[i++]);
  }
  printf("Source Program:\n%s\n", source);

  trim(source);
  parseSource(source, list);

  return 0;
}

