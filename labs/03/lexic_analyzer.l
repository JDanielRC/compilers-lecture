%{
#include <stdio.h>
%}

floatdcl [f]
intdcl [i]
assign [=]
print [p]
plus [+]
minus [-]
times [*]
divide [/]
id [a-eg-hj-oq-z]+
inum [0-9]+
fnum [0-9]+["."][0-9]+
eol \n


%%

"//".* {}
{floatdcl} {fprintf(yyout, "floatdcl ");}
{intdcl} {fprintf(yyout, "intdcl ");}
{assign} {fprintf(yyout, "= ");}
{print} {fprintf(yyout, "print ");}
{plus} {fprintf(yyout, "+ ");}
{minus} {fprintf(yyout, "- ");}
{times} {fprintf(yyout, "* ");}
{divide} {fprintf(yyout, "/ ");}
{id} {fprintf(yyout, "id ");}
{eol} {fprintf(yyout, "\n");}
{inum} {fprintf(yyout, "inum ");}
{fnum} {fprintf(yyout, "fnum ");}



%%

int main(int argc, char** argv){

    extern FILE *yyin, *yyout; 
    if (argc == 2){
        yyin = fopen(argv[1], "r");
        yyout = fopen("lex.txt", "w");
        yylex();
    } else if (argc == 1){
        yyout = fopen("lex.txt", "w");
        yylex();
    } else{
        printf("Wrong usage of arguments [./lexical_scan (input)] or [./lexical_scan < input] \n");
    }
    
    
    return 0;
}
