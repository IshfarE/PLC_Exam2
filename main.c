#include "syn.h"

int main(void) 
{
  if ((in_fp = fopen("hError1.in", "r")) != NULL)
  {
    extract();  //lex(); , statement();
	 	startup();
  }
  else if ((in_fp = fopen("errorfree2.in", "r")) != NULL)
  {
    extract();  
	 	startup();
  }
  else if ((in_fp = fopen("synerror.in", "r")) != NULL)
  {
    extract();  
	 	startup();
  }
  else if ((in_fp = fopen("lexerror.in", "r")) != NULL)
  {
    extract();  
	 	startup();
  }
  else
  {
	  printf("ERROR - cannot open files \n"); 	
	}
  return 0;
} 