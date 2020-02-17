token_type Reserved(char *str)
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


-----------------------------------------
FILE *fp;
  fp = fopen("input.txt", "r");
  char aSingleLine[MAX_CODE_LENGTH];

  while(!feof(fp))
  {
    fgets(aSingleLine, MAX_CODE_LENGTH, fp);
    puts(aSingleLine);
  }

  fclose(fp);
  return 0;

///////////////////////////////////////////////////////
bool symboltable(char symbol)
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

int parse(char *str, lexeme list[])
{
  int i = 0, j = 0;
  int a;
  // Table of reserved word names
  char reserved[14][9] = { "const", "var", "procedure", "call", "begin", "end",
                           "if", "then", "else", "while", "do", "read", "write",
                           "odd" };
  lexeme *l;
  while(str[i] != '\0')
  {
    if(str[i] == 'c' && str[i+1] == 'o' && str[i+2]=='n' && str[i+3] == 's' && str[i+4] == 't')
    {
      l = createLexeme(constsym, "const");
      list[j++] = l;
      // loop through whitespace
      i += 5;
      while (!isspace(str[i++]));
      // capture identifier (and make sure it's valid)
      // capture identifier value (and make sure it's valid)
      // also capturing symbols
    }

    if(str[i] == 'v' && str[i+1] == 'a' && str[i+2]=='r')
    {
      //printf("var\n");
      l = createLexeme(varsym, "var");
      list[j++] = l;

      i+= 3;
      while(isspace(str[i]))
      {
        i++;
      }

      while(str[i] != ';')
      {


        if(!isalpha(str[i]))
        {
          printf("Error: variable starts off with something that is not a letter\n");
          return 0;
        }
        a = i;
        while(str[i] != ',')
        {
          if(isspace(str[i]))
          {
            b--;

          }
          b++;
          i++;
          if((b-a) > MAX_IDENT_LENGTH)
          {
            printf("Error: variable is too long.\n");
            return 0;
          }

        }

        if(str[i] == ',' )
        {

        }
      }




      // return true;
    }

    if(str[i] == 'p' && str[i+1] == 'r' && str[i+2]=='o' && str[i+3] == 'c' &&
      str[i+4] == 'e' | str[i+5] == 'd' && str[i+6]=='u' && str[i+7] == 'r'
      && str[i+8] == 'e' )
    {
      printf("procedure\n");
      l = createLexeme(procsym, "procedure");
      list[j++] = l;

      i+= 9;
      while(isspace(str[i]))
      {
        i++;
      }

      while( str[i] != ';')
      {

      }
      // return true;
    }

    if(str[i] == 'c' && str[i+1] == 'a' && str[i+2]=='l' && str[i+3] == 'l')
    {
      printf("call\n");
      l = createLexeme( callsym, "call");
      list[j++] = l;

      i+= 4;
      while(isspace(str[i]))
      {
        i++;
      }
      // return true;
    }

    if(str[i] == 'b' && str[i+1] == 'e' && str[i+2]=='g' && str[i+3] == 'i' && str[i+4] == 'n')
    {
      printf("begin\n");
      l = createLexeme( beginsym, "begin");
      list[j++] = l;

      i+= 5;
      while(isspace(str[i]))
      {
        i++;
      }
      // return true;
    }

    if(str[i] == 'e' && str[i+1] == 'n' && str[i+2]=='d')
    {
      printf("end\n");
      l = createLexeme( endsym, "end");
      list[j++] = l;

      i+= 3;
      while(isspace(str[i]))
      {
        i++;
      }
      // return true;
    }

    if(str[i] == 'i' && str[i+1] == 'f' )
    {
      printf("if\n");
      l = createLexeme( ifsym, "if");
      list[j++] = l;

      i+= 2;
      while(isspace(str[i]))
      {
        i++;
      }
      // return true;
    }

    if(str[i] == 't' && str[i+1] == 'h' && str[i+2]=='e' && str[i+3] == 'n')
    {
      l = createLexeme( thensym, "then");
      list[j++] = l;

      i+= 4;
      while(isspace(str[i]))
      {
        i++;
      }

    }

    if(str[i] == 'e' && str[i+1] == 'l' && str[i+2]=='s' && str[i+3] == 'e')
    {
      printf("else\n");
      l = createLexeme( elsesym, "else");
      list[j++] = l;

      i+= 4;
      while(isspace(str[i]))
      {
        i++;
      }
      // return true;
    }

    if(str[i] == 'w' && str[i+1] == 'h' && str[i+2]=='i' && str[i+3] == 'l' && str[i+4] == 'e')
    {
      printf("while\n");
      l = createLexeme( whilesym, "while");
      list[j++] = l;

      i+= 5;
      while(isspace(str[i]))
      {
        i++;
      }
      // return true;
    }

    if(str[i] == 'd' && str[i+1] == 'o')
    {
      printf("do\n");
      l = createLexeme( dosym, "do");
      list[j++] = l;

      i+= 2;
      while(isspace(str[i]))
      {
        i++;
      }
      // return true;
    }

    if(str[i] == 'r' && str[i+1] == 'e' && str[i+2]=='a' && str[i+3] == 'd')
    {
      printf("read\n");
      l = createLexeme( readsym, "read");
      list[j++] = l;

      i+= 4;
      while(isspace(str[i]))
      {
        i++;
      }
      // return true;
    }

    if(str[i] == 'w' && str[i+1] == 'r' && str[i+2]=='i' && str[i+3] == 't' && str[i+4] == 'e')
    {
      printf("write\n");
      l = createLexeme( writesym, "write");
      list[j++] = l;

      i+= 5;
      while(isspace(str[i]))
      {
        i++;
      }
      // return true;
    }

    if(str[i] == 'o' && str[i+1] == 'd' && str[i+2]=='d')
    {
      printf("odd\n");
      l = createLexeme( oddsym, "odd");
      list[j++] = l;

      i+= 3;
      while(isspace(str[i]))
      {
        i++;
      }
      // return true;
    }
  }
  return;
}
