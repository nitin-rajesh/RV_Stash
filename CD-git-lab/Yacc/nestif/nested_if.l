%{
    #include"y.tab.c"
%}

identifier [a-zA-Z][a-zA-Z0-9]*
infix [-+*/%=&|]|[><=]=?|"&&"|"||"
unary "++"|"--"|[*!\^]
literal [0-9]+
else_keyword "else"
if_keyword "if"

%%
{if_keyword} return IF;
{else_keyword} return ELSE;
{unary} return UNARY;
{infix} return INFIX;
{literal} return LITERAL;
{identifier} return ID;
[(){};] return *yytext;
"\n\n" return 0;
[ \n\t] ;
%%

int yywrap(){
    return 1;
}