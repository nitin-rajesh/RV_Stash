%{
    #include"y.tab.c"
%}

NUM [0-9]+
LETTER [a-zA-Z]+

%%
{NUM} {yylval.sym = (char)yytext[0]; return INTEGER;}
{LETTER} {yylval.sym = (char)yytext[0];return ALPHA;}
\n return 0;
. return yytext[0];
%%

int yywrap(){
    return 1;
}