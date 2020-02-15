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

void parseSource(char *src, lexeme *list);
char *trim(char *str);
bool isIdentifier(char *str);
bool isNumber(char *str);
void isReserved(char *str);
bool issymbol(char c);

// gets rid of comments by overwriting all character within the comments and the
// comment markers themselves
char *trim(char *str)
{
  int lp = 0, rp, diff, i, len = strlen(str);
  i=0;
  char trimmed[MAX_CODE_LENGTH];

  while (str[lp] != '\0')
  {

    if (str[lp] == '/' && str[lp + 1] == '*')
    {
      rp = lp + 2;
      while (str[rp] != '*' && str[rp + 1] != '/')
      {
        rp++;
      }
      //rp += 2; // rp = rp + 2
      lp= rp+2;
    }
    trimmed[i] = str[lp];
    i++;
    lp++;
  }
  printf("\nTrimmed input:\n*%s*\n", trimmed);
  return;
}

// checks for errors and prints tokenized output
void parseSource(char *src, lexeme *list)
{
  char buffer[MAX_CODE_LENGTH];
  int i=0, j = 0;
  while(src[i] != '\0')
  {
    if(isalpha(src[i]) == false && isdigit(src[i]) == false && !issymbol(src[i]) && !isspace(src[i]))
    {
      printf("invalid symbol\n");
      return;
    }
    i++;

  }

  i=0;
  // capturing substring to be evaluated
  while(src[i] != '\0')
  {
    if(isspace(src[i]))
    {
      i++;
    }
    if(isalpha(src[i]) || isdigit(src[i]))
    {
      while (!issymbol(src[i]))
      {
        buffer[j++] = src[i++];
      }
    }

    // evaluating substring
    if (isReserved(buffer))
    {
      if (strcmp(buffer, "const") == 0)
      {
        // read further in the string for number to be evaluated

      }
      if (strcmp(buffer, "var") == 0)
      {
        // var stuff
      }
      if (strcmp(buffer, "procedure") == 0)
      {

      }
      if (strcmp(buffer, "call") == 0)
      {

      }
      if (strcmp(buffer, "begin") == 0)
      {

      }
      if (strcmp(buffer, "end") == 0)
      {

      }
      if (strcmp(buffer, "if") == 0)
      {

      }
      if (strcmp(buffer, "then") == 0)
      {

      }
      if (strcmp(buffer, "else") == 0)
      {

      }
      if (strcmp(buffer, "while") == 0)
      {

      }
      if (strcmp(buffer, "do") == 0)
      {

      }
      if (strcmp(buffer, "read") == 0)
      {

      }
      if (strcmp(buffer, "write") == 0)
      {

      }
      if (strcmp(buffer, "odd") == 0)
      {

      }
    }
  }


bool issymbol(char c)
{
  // Table of special symbols
  char symbols[13] = { '+', '-', '*', '/', '(', ')', '=', ',', '.', '<', '>', ';',
                       ':' };


  for(int i=0; i<13; i++)
  {
    if(c == symbols[i])
    {
        return true;
    }
  }
  return false;
}


isReserved(src);
  // while ()
}

// returns true if the string is a valid identifier and false otherwise
bool isIdentifier(char *str)
{
  int i = 1, len = strlen(str);
  if (!isalpha(str[0]) && len > MAX_IDENT_LENGTH)
  {
    return false;
  }

  for (i = 1; i < len; i++)
  {
    if (!isalpha(str[i]) && !isdigit(str[i]))
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
void isReserved(char *str)
{
  int i=0;
  // Table of reserved word names
  char reserved[14][9] = { "const", "var", "procedure", "call", "begin", "end",
                           "if", "then", "else", "while", "do", "read", "write",
                           "odd" };
while(str[i] != '\0'){

  if(str[i] == 'c' && str[i+1] == 'o' && str[i+2]=='n' && str[i+3] == 's' && str[i+4] == 't')
  {
    printf("constant\n");
    // return true;

  }

  if(str[i] == 'v' && str[i+1] == 'a' && str[i+2]=='r')
  {
    printf("var\n");
    // return true;
  }

  if(str[i] == 'p' && str[i+1] == 'r' && str[i+2]=='o' && str[i+3] == 'c' && str[i+4] == 'e' | str[i+5] == 'd' && str[i+6]=='u' && str[i+7] == 'r' && str[i+8] == 'e' )
  {
    printf("procedure\n");
    // return true;
  }

  if(str[i] == 'c' && str[i+1] == 'a' && str[i+2]=='l' && str[i+3] == 'l')
  {
    printf("call\n");
    // return true;
  }

  if(str[i] == 'b' && str[i+1] == 'e' && str[i+2]=='g' && str[i+3] == 'i' && str[i+4] == 'n')
  {
    printf("begin\n");
    // return true;
  }

  if(str[i] == 'e' && str[i+1] == 'n' && str[i+2]=='d')
  {
    printf("end\n");
    // return true;
  }

  if(str[i] == 'i' && str[i+1] == 'f' )
  {
    printf("if\n");
    // return true;
  }

  if(str[i] == 't' && str[i+1] == 'h' && str[i+2]=='e' && str[i+3] == 'n')
  {
    printf("then\n");
    // return true;
  }

  if(str[i] == 'e' && str[i+1] == 'l' && str[i+2]=='s' && str[i+3] == 'e')
  {
    printf("else\n");
    // return true;
  }

  if(str[i] == 'w' && str[i+1] == 'h' && str[i+2]=='i' && str[i+3] == 'l' && str[i+4] == 'e')
  {
    printf("while\n");
    // return true;
  }

  if(str[i] == 'd' && str[i+1] == 'o')
  {
    printf("do\n");
    // return true;
  }

  if(str[i] == 'r' && str[i+1] == 'e' && str[i+2]=='a' && str[i+3] == 'd')
  {
    printf("read\n");
    // return true;
  }

  if(str[i] == 'w' && str[i+1] == 'r' && str[i+2]=='i' && str[i+3] == 't' && str[i+4] == 'e')
  {
    printf("write\n");
    // return true;
  }

  if(str[i] == 'o' && str[i+1] == 'd' && str[i+2]=='d')
  {
    printf("odd\n");
    // return true;
  }

  i++;

}

  return;
}

int main(int argc, char **argv)
{
  // printf("Reserved words: \n");
  // for (int i = 0; i < 14; i++)
  // {
  //   printf("%s\n", reserved[i]);
  // }
  char c, source[MAX_CODE_LENGTH];
  lexeme list[MAX_CODE_LENGTH];
  FILE *fp = fopen(argv[1], "r");
  int i = 0;

  fscanf(fp, "%c", &c);
  while (!feof(fp))
  {
    source[i++] = c;
    fscanf(fp, "%c", &c);
  }
  // source[i] = c;
  fclose(fp);

  printf("Source Program:\n%s\n", source);

  trim(source);
  parseSource(source, list);

  return 0;
}
