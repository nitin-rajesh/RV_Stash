%{
    #include"y.tab.c"
%}

%%
[0-9]+ {yylval = atoi(yytext); return INTEGER;}
[-+*/()] return *yytext;
[ \t] ;
\n return NEWLINE;
. printf("Unexpected");

%%

int yywrap(){
    return 1;
}