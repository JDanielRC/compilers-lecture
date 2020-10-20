%{
#include <stdio.h>
#include "y.tab.h"
extern int yylval;
%}

intnums [0-9]+
open [\(]
closed [\)]


%%
{intnums}  {yylval = atoi(yytext); return intnum;}
{open}       {return leftParenthesis;}
{closed}       {return rightParenthesis;}
[\t]
\n return 0;
. return yytext[0];
%%