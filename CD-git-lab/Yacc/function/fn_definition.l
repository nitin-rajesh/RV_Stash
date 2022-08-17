%{
    #include"y.tab.c"
%}

identifier [a-zA-Z][a-zA-Z0-9]*
infix [-+*/%=&|]|[><=]=?|"&&"|"||"
unary "++"|"--"|[*!\^]
literal [0-9]+|\"[^"]*\"
keyword "int "|"float "|"double "|"char "|"void "|"long "|"if "|"else "|"for"|"while"|"goto "|"do"|"return "


%%
{keyword} return KEYWORD;
{unary} return UNARY;
{infix} return INFIX;
{literal} return LITERAL;
{identifier} return ID;
[(){};,] return *yytext;
"\n\n" return 0;
[ \n\t] ;
%%

int yywrap(){
    return 1;
}