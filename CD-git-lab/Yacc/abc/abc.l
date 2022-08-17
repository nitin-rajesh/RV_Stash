%{
    #include"y.tab.c"
%}

%%
[abc] {return yytext[0];};
\n return 0;
. {printf("Unrecognized\n");return 1;}
%%

int yywrap(){
    return 1;
}