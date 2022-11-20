#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#include "langauge.c"
/* Global declarations */
/* Variables */
int ch_Class;                 //class of characters 
char lx_m_e[100];               //variable for lexeme (100 characters max)
char charFol;                //the following character
int reachLex;                  //length of the lexeme
int curr_TK;                   //Current token
int followTK;                  //the following token
FILE *in_fp;
char nextkey;                  //following key

/* Function declarations */
int glossary(char ch);        //method for looking up the glossary of tokens
void new_Char(void);           //Method for adding new characters to a previous character
void extract(void);            //Method for extracting characters
void omitBlnk(void);        //Method for extracting only chracters that are not blank spaces
int lex(void);              //Method for analyzing mathematical operations
void error_0(void);          //Method for errors

//Classes of characters
#define ALPHABET 0
#define NUMBER 1

#define MYSTERY 10
#define Beginner 11
#define Finisher 12

//Token Codes
#define INTEGER 20
#define IDENTIFY 21
#define ASSGNMNT 22

//Math operators
#define ADDITION 30
#define SUBTRACT 31
#define MULTIPLY 32
#define DIVIDE 33
#define MODULUS 34

//Open or close
#define STARTPAR 40
#define ENDPAR 41
#define STARTBRK 42
#define ENDBRK 43

//Special characters
#define COMMA_V 50
#define S_COLON 51
#define PERIOD 52

//Comparison
#define SMALLER 60
#define LARGER 61
#define SMALLERQ 62
#define LARGERQ 63
#define EQUAL_V 64
#define NOTEQUAL 65

//If statements
#define IF_STMT 70

//Loops
#define CIRCUIT 80
#define NUMERICS 81


int glossary(char ch) 
{
//  == cant be passed in <=
	 switch (ch) 
   {
		 case '(':
			 new_Char();
			 followTK = STARTPAR;
			 break;
		 case ')':
			 new_Char();
			 followTK = ENDPAR;
			 break;
		 case '+':
			 new_Char();
			 followTK = ADDITION;
			 break;
		 case '-':
			 new_Char();
			 followTK = SUBTRACT;
			 break;
		 case '*':
			 new_Char();
			 followTK = MULTIPLY;
			 break;
		 case '/':
			 new_Char();
			 followTK = DIVIDE;
			 break;
		 case '=':
			 new_Char();
			 followTK = ASSGNMNT;
			 break;
		 case '%':
			 new_Char();
			 followTK = MODULUS;
			 break;
		 case ';':
			 new_Char();
			 followTK = S_COLON;
			 break;
		 case ',':
			 new_Char();
			 followTK = COMMA_V;
			 break;
		 case '{':
			 new_Char();
			 followTK = STARTBRK;
			 break;
		 case '}':
			 new_Char();
			 followTK = ENDBRK;
			 break;
		 case '.':
			 new_Char();
			 followTK = PERIOD;
			 break;
		 case '<':
			 new_Char();
			 followTK = SMALLER;
			 break;
		 case '>':
			 new_Char();
			 followTK = LARGER;
			 break;
     case '@':
       new_Char();
			 followTK = Beginner;
			 break;
     case '^':
      new_Char();
      followTK = Finisher;
      break;
     case '#':
      new_Char();
      followTK = NUMERICS;
      break;
    
     case '!':
      new_Char();
      followTK = NOTEQUAL;
      break;
     
		 default:
			 new_Char();
			 followTK = EOF;
			 break;
	 }
	 return followTK;
}
void new_Char(void) 
{
	if (reachLex < 82 && reachLex != 10) 
  {
		lx_m_e[reachLex++] = charFol;
		lx_m_e[reachLex] = '\0';
	} 
  else
  {
    printf("Error - lexeme is too long \n");  
  }
}

// extract - get the next character of input and determine character class (transitions on every possible character)
void extract(void) 
{
	 if ((charFol = getc(in_fp)) != EOF) 
   {
		 if (isalpha(charFol))
     {
      ch_Class = ALPHABET;  
     } 
		 else if (isdigit(charFol)) 
     {
      ch_Class = NUMBER;  
     }
      
		 else 
     {
      ch_Class = MYSTERY;  
     }
	 } 
   else
   {
     ch_Class = EOF;  
   } 	
}

// omitBlnk - call extract until non-blank character
void omitBlnk(void) 
{
	while (isspace(charFol))
	extract();
}

void error_0(void)
{
	printf("ERROR STOP");
  exit(0);
}

// lex - lexical analyzer for math expressions
int x;
int lex(void) 
{
	reachLex = 0;
	omitBlnk();
  int x;
  int y;
	switch (ch_Class) 
  {
		//Identifiers ([a-zA-Z][a-zA-Z0-9]*  is RegEx for an identifier)
		case ALPHABET:
      y =1;
			new_Char();
			extract();
			while (ch_Class == ALPHABET) 
      {
        y++;
			  new_Char();
				extract();
			}
      if(y>=6 && y<=8 && lx_m_e[0]!='c' && lx_m_e[0] !='w' && lx_m_e[0] != 'n' )
      {
			  followTK = IDENTIFY;
      }
      else if(lx_m_e[0]=='c'&&lx_m_e[1]=='i'&&lx_m_e[2]=='r'&&lx_m_e[3]=='c') 
      {
        followTK = CIRCUIT;
      }
      else if(lx_m_e[0]=='w'&&lx_m_e[1]=='h'&&lx_m_e[2]=='a'&&lx_m_e[3]=='t' ) 
      {
        followTK = IF_STMT;
      }
      else if((lx_m_e[1]!='i'||lx_m_e[2]!='r'||lx_m_e[3]!='c') && y>=6 && y<=8)
      {
        followTK = IDENTIFY;
      }  
      else
      {
        error_0();
      }
    break;
		// Integer literals
    //  [0-9]+  is the regular expression for an integer, [0-9]*.[0-9]+[f|d]?  is the regular expression for an FLOAT_LIT (e.g., .0, 0.0, 0.0324f, 0.0324d)
    
		case NUMBER:
			new_Char();
			extract();
			while (ch_Class == NUMBER) 
      {
				new_Char();
				extract();
			}
      if( charFol == 'v' || charFol == 'r' || charFol == 'e' )
      {
			  new_Char();
				extract();
      }
      if( charFol != '.')
      {
			  followTK = INTEGER;
      } 
      else 
      {
        error_0();
  			// new_Char();
	  		// extract();
		  	while (ch_Class == NUMBER) 
        {
			  	new_Char();
				  extract();
        }
        if( charFol == 'v' || charFol == 'r' || charFol == 'e' )
        {
			  	new_Char();
				  extract();
        } 
			  //followTK = FLOAT_LIT;
      }
		 	break;
		
		  case MYSTERY: // Parentheses and operators ^[a-zA-Z0-9]  is the RegEx for an special charater
        if( charFol == '.')
        {
  			  new_Char();
	  		  extract();
          if(ch_Class == NUMBER )
          {
		  	    while (ch_Class == NUMBER) 
            {
			  	    new_Char();
				      extract();
			      }
            if( charFol == 'd' || charFol == 'f' )
            {
			  	    new_Char();
				      extract();
            }
			    //  followTK = FLOAT_LIT;
          }
          followTK = PERIOD;
        } 
      else 
      {
			  glossary(charFol);
			  extract();
        if ( followTK == SMALLER && charFol == '=' ) 
        {
          new_Char();
          extract();
          followTK = SMALLERQ;
        }
        else if ( followTK == LARGER && charFol == '=' ) 
        {
          new_Char();
          extract();
          followTK = LARGERQ;
        }
        else if ( followTK == ASSGNMNT && charFol == '=' ) 
        {
          new_Char();
          extract();
          followTK = EQUAL_V;
        }
      }
			break;
			//EOF 
		case EOF:
			 followTK = EOF;
			 lx_m_e[0] = 'E';
			 lx_m_e[1] = 'O';
			 lx_m_e[2] = 'F';
			 lx_m_e[3] = '\0';
		 	break;
    case Beginner:
      followTK= Beginner; 
	} // End of switch
  switch(followTK)
  {
    case 11:
      printf("Token: Beginner, Lexeme: %s\n", lx_m_e);
      break;
    case 12:
      printf("Token: Finisher, Lexeme: %s\n", lx_m_e);
      break;
    
    case 20:
      printf("Token: INTEGER, Lexeme: %s\n", lx_m_e);
      break;
    case 21:
      printf("Token: IDENTIFY, Lexeme: %s\n", lx_m_e);
      break;
    case 22:
      printf("Token: ASSGNMNT, Lexeme: %s\n", lx_m_e);
      break;
    
    case 30:
      printf("Token: ADDITION, Lexeme: %s\n", lx_m_e);
      break;
    case 31:
      printf("Token: SUBTRACT, Lexeme: %s\n", lx_m_e);
      break;
    case 32:
      printf("Token: MULTIPLY, Lexeme: %s\n", lx_m_e);
      break;
    case 33:
      printf("Token: DIVIDE, Lexeme: %s\n", lx_m_e);
      break;
    case 34:
      printf("Token: MODULUS, Lexeme: %s\n", lx_m_e);
      break;
    
    case 40:
      printf("Token: STARTPAR, Lexeme: %s\n", lx_m_e);
      break;
    case 41:
      printf("Token: ENDPAR, Lexeme: %s\n", lx_m_e);
      break;
    case 42:
      printf("Token: STARTBRK, Lexeme: %s\n", lx_m_e);
      break;
    case 43:
      printf("Token: ENDBRK, Lexeme: %s\n", lx_m_e);
      break;

    case 51:
      printf("Token: S_COLON, Lexeme: %s\n", lx_m_e);
      break;
    
    case 60:
      printf("Token: SMALLER, Lexeme: %s\n", lx_m_e);
      break;
    case 61:
      printf("Token: LARGER, Lexeme: %s\n", lx_m_e);
      break;
    case 62:
      printf("Token: SMALLERQ, Lexeme: %s\n", lx_m_e);
      break;
    case 63:
      printf("Token: LARGERQ, Lexeme: %s\n", lx_m_e);
      break;
    case 64:
      printf("Token: EQUAL_V, Lexeme: %s\n", lx_m_e);
      break;
    case 65:
      printf("Token: NOTEQUAL, Lexeme: %s\n", lx_m_e);
      break;
    
    case 70:
      printf("Token: IF_STMT, Lexeme: %s\n", lx_m_e);
      break;
      
    case 80:
      printf("Token: CIRCUIT, Lexeme: %s\n", lx_m_e);
      break;
    case 81:
      printf("Token: NUMERICS, Lexeme: %s\n", lx_m_e);
      break;
  }  //	 printf("Token: %d, Lexeme: %s\n",
	 return followTK; //	 followTK, lx_m_e);
} // End of function lex