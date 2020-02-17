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
	lexeme *l = malloc(1 * sizeof(lexeme));
	l->type = t;
  l->lexeme = str;
	return l;
}

// gets rid of comments by overwriting all character within the comments and the
// comment markers themselves
void trim(char *str)
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

int parse(char *str, lexeme list[])
{
  int i = 0, j = 0, k = 0, diff, x, length = 0;
  // Table of reserved word names
  char reserved[14][9] = { "const", "var", "procedure", "call", "begin", "end",
                           "if", "then", "else", "while", "do", "read", "write",
                           "odd" };
  char buffer[MAX_CODE_LENGTH];
  lexeme *l;
  while(str[i] != '\0')
  {
    // const
    if(str[i] == 'c' && str[i+1] == 'o' && str[i+2]=='n' && str[i+3] == 's' && str[i+4] == 't')
    {
      l = createLexeme(constsym, "const");
      list[j++] = *l;
      // loop through whitespace
      i += 5;
      while (!isspace(str[i++]));
      // capture identifier (and make sure it's valid)
      if (isalpha(str[i]))
      {
        // capture identifier as substring and put in list
        i = k;
        while (!symboltable(str[k++]))
        {
          if (!isspace(str[k]))
          {
            length++;
          }
        }
        if ((length) > MAX_IDENT_LENGTH)
        {
          printf("Err: number too long\n");
          return 0;
        }
        // copying array into buffer
        k = i;
        for (x = 0; x < length; x++)
        {
          buffer[x] = str[k++];
        }
        str[k] = '\0';
        l = createLexeme(identsym, buffer);
        list[j++] = *l;
      }
      else
      {
        printf("Err: invalid identifier\n");
        return 0;
      }

      // capture identifier value
      i = k;
      while (!isspace(str[i++]));
      k = i;
      while (isdigit(str[k++]));
      length = k - i;
      if (length > MAX_NUM_LENGTH)
      {
        printf("Err: number too long\n");
        return 0;
      }
      for (x = 0; x < length; x++)
      {
        buffer[x] = str[i++];
      }
      l = createLexeme(numbersym, buffer);
      list[j++] = *l;
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
  }
  return 1;
}

int main(int argc, char **argv)
{
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
  fclose(fp);

  printf("Source Program:\n%s\n", source);

  trim(source);
  parse(source, list);

  return 0;
}
