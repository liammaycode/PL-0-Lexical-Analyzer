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

typedef enum
{
  nulsym = 1, identsym = 2, numbersym = 3, plussym = 4, minussym = 5, multsym = 6,
  slashsym = 7, oddsym = 8, eqlsym = 9, neqsym = 10, lessym = 11, leqsym = 12,
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

char* trim(char *str);
int parse(char *code, lexeme list[]);
bool isReserved(char *str);
token_type reserved(char *str);
lexeme *createLexeme(token_type t, char *str);
bool isNumber(char *str);
bool isSymbol(char symbol);
void output(lexeme list[], int count);

lexeme *createLexeme(token_type t, char *str)
{
	// calloc() initializes the 'left' and 'right' pointers to NULL for us.
	lexeme *l = malloc(1 * sizeof(lexeme));
	l->type = t;
  l->lexeme = malloc(sizeof(char) * MAX_IDENT_LENGTH);
  strcpy(l->lexeme, str);
	return l;
}

char* trim(char *str)
{
  int lp = 0, rp, diff, i, len = strlen(str);
  i=0;
  char *trimmed = malloc(sizeof(char) * MAX_CODE_LENGTH);

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
      lp= rp;
    }
    trimmed[i] = str[lp];
    i++;
    lp++;
  }
  // printf("\nTrimmed input:\n*%s*\n", trimmed);
  return trimmed;
}

int parse(char *code, lexeme list[])
{
  lexeme *lexptr;
  int lp = 0, rp, length, i, listIndex = 0;
  char buffer[MAX_CODE_LENGTH];
  token_type t;

  // looping through string containing input
  while (code[lp] != '\0')
  {
    // ignoring whitespace
    if (isspace(code[lp]))
    {
      // printf("whitespace skipped...\n");
      lp++;
    }
    if (isalpha(code[lp]))
    {
      rp = lp;

      // capturing length of substring
      while (isalpha(code[rp]) || isdigit(code[rp]))
      {
        //printf("character %c at code[%d] is alphanumeric\n", code[rp], rp);
        rp++;
      }
      length = rp - lp;
      //printf("length of string to be captured: %d\n", length);

      // checking for ident length error
      if (length > MAX_IDENT_LENGTH)
      {
        printf("Err: ident length too long\n");
        return 0;
      }

      // creating substring
      for (i = 0; i < length; i++)
      {
        buffer[i] = code[lp + i];
      }
      buffer[i] = '\0';
      lp = rp;
      //printf("\nsubstring *%s* recorded\n\n", buffer);

      // adds reserved words to lexeme array
      if (isReserved(buffer))
      {
        t = reserved(buffer);
        //printf("\n(125) creating lexeme for %s\n\n", buffer);
        lexptr = createLexeme(t, buffer);
        list[listIndex++] = *lexptr;
      }
      // must be a identifier at this line
      else
      {
        t = identsym;
        //printf("\n(133) creating lexeme for %s\n\n", buffer);
        lexptr = createLexeme(t, buffer);
        list[listIndex++] = *lexptr;
      }
    }
    else if (isdigit(code[lp]))
    {
      rp = lp;

      i = 0;
      // capturing length of substring
      while (isdigit(code[lp + i]))
      {
        //printf("traversing number...\n");
        rp++;
        i++;
      }
      length = rp - lp;

      // checking for ident length error
      if (length > MAX_NUM_LENGTH)
      {
        printf("Err: number length too long\n");
        return 0;
      }

      // creating substring
      for (i = 0; i < length; i++)
      {
        buffer[i] = code[lp + i];
      }
      buffer[i] = '\0';
      lp = rp;
      //printf("\nsubstring *%s* recorded\n\n", buffer);

      t = numbersym;
      //printf("\n(167) creating lexeme for %s\n\n", buffer);
      lexptr = createLexeme(t, buffer);
      list[listIndex++] = *lexptr;
    }
    //create an lexeme for the symbol//call createlex w t and sym
    else if (isSymbol(code[lp]))
    {
      if (code[lp] == '+')
      {
        t = 4;
      }
      if (code[lp] == '-')
      {
        t = 5;
      }
      if (code[lp] == '*')
      {
        t = 6;
      }
      if (code[lp] == '/')
      {
        t = 7;
      }
      if (code[lp] == '(')
      {
        t = 15;
      }
      if (code[lp] == ')')
      {
        t = 16;
      }
      if (code[lp] == '=')
      {
        t = 9;
      }
      if (code[lp] == ',')
      {
        t = 17;
      }
      if (code[lp] == '.')
      {
        t = 19;
      }
      if (code[lp] == '<')
      {
        t = 11;
      }
      if (code[lp] == '>')
      {
        t = 13;
      }
      if (code[lp] == ';')
      {
        t = 18;
      }
      if (code[lp] == ':')
      {
        t = 20;
      }

      buffer[0] = code[lp];
      buffer[1] = '\0';
      lexptr = createLexeme(t, buffer);
      list[listIndex++] = *lexptr;

      lp++;
    }
  }
  return listIndex;
}

bool isSymbol(char symbol)
{
  char validsymbols[13] = {'+', '-', '*', '/', '(', ')', '=', ',', '.', '<', '>',  ';', ':'};

  for(int i=0; i<13; i++)
  {
    if(symbol == validsymbols[i])
    {
      return 1;
    }
  }
  return 0;
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

token_type reserved(char *str)
{
  // Table of reserved word names
  char reserved[14][9] = { "const", "var", "procedure", "call", "begin", "end",
                           "if", "then", "else", "while", "do", "read", "write",
                           "odd" };

  if (str[0] == 'b')
  {
    if (strcmp(reserved[4], str) == 0)
    {
      return 21;
    }
  }
  if (str[0] == 'c')
  {
    if (strcmp(reserved[0], str) == 0)
    {
      return 28;
    }
    else if (strcmp(reserved[3], str) == 0)
    {
      return 27;
    }
  }
  if (str[0] == 'd')
  {
    if (strcmp(reserved[10], str) == 0)
    {
      return 26;
    }
  }
  if (str[0] == 'e')
  {
    if (strcmp(reserved[5], str) == 0)
    {
      return 22;
    }
    else if (strcmp(reserved[8], str) == 0)
    {
      return 33;
    }
  }
  if (str[0] == 'i')
  {
    if (strcmp(reserved[6], str) == 0)
    {
      return 23;
    }
  }
  if (str[0] == 'o')
  {
    if (strcmp(reserved[13], str) == 0)
    {
      return 8;
    }
  }
  if (str[0] == 'p')
  {
    if (strcmp(reserved[2], str) == 0)
    {
      return 30;
    }
  }
  if (str[0] == 'r')
  {
    if (strcmp(reserved[11], str) == 0)
    {
      return 32;
    }
  }
  if (str[0] == 't')
  {
    if (strcmp(reserved[7], str) == 0)
    {
      return 24;
    }
  }
  if (str[0] == 'v')
  {
    if (strcmp(reserved[1], str) == 0)
    {
      return 29;
    }
  }
  if (str[0] == 'w')
  {
    if (strcmp(reserved[9], str) == 0)
    {
      return 25;
    }
    else if (strcmp(reserved[12], str) == 0)
    {
      return 31;
    }
  }
  return false;
}

void output(lexeme list[], int count)
{
  int i = 0;
  printf("Lexeme Table:\nLexeme\t\tToken Type\n");
  for (i = 0; i < count; i++)
  {
    printf("%s\t\t%d\n", list[i].lexeme, list[i].type);
  }

  printf("\nLexeme List:\n");
  for(int i=0; i<count; i++)
  {
    printf("%d ", list[i].type);
    if(list[i].type == 2 || list[i].type == 3)
    {
      printf("%s ", list[i].lexeme);
    }
  }
  printf("\n");
}

int main(int argc, char **argv)
{
  FILE *fp;
  fp = fopen(argv[1], "r");
  char aSingleLine[MAX_CODE_LENGTH], code[MAX_CODE_LENGTH] = {'\0'};
  lexeme list[MAX_CODE_LENGTH] = {'\0'};
  int count;

  while(!feof(fp))
  {
    fgets(aSingleLine, MAX_CODE_LENGTH, fp);
    strcat(code, aSingleLine);
  }
  printf("Input:\n%s\n", code);

  strcpy(code, trim(code));
  count = parse(code, list);
  output(list, count);

  fclose(fp);
  return 0;
}
