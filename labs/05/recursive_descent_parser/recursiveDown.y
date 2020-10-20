// E -> T | T + E
// T -> int | int * T | (E)

%{
#include <stdio.h>
%}

%token intnum leftParenthesis rightParenthesis
%left '+'
%left '*'

%%

E:  T
            {
                $$ = $1;
            }
            |
            T '+' E
            {
              $$ = $1 + $3;
            }
            ;
T: leftParenthesis E rightParenthesis
            {
                $$ = ($2);
            }
            |
            intnum '*' T 
            {
                $$ = $1 * $3;
            }
            |
            intnum
            ;
%%


int main(){
  if(yyparse() == 0){
    printf("Parsed sucessfully \n");
  }else{
    printf("Error \n");
    return 1;
  }
  
}

int yyerror(problem)
char *problem;
{
  fprintf(stderr, "%s, ending parsing. \n",problem);
}

yywrap(){
  return(1);
}