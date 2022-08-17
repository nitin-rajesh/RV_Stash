identifier [_]?[a-zA-Z]+[a-zA-Z0-9]*
operator [-+*/%=]|[<>=]=?|"++"|"--"
keyword "int"|"float"|"double"|"char"|"void"|"long"|"if"|"else"|"for"|"while"|"goto"|"do"|"return"

%{
    #include<stdio.h>
    int id = 0, op = 0, key = 0;
%}

%%
{keyword} {key++;printf("<%s,ID>",yytext);}
{identifier} {id++;printf("<%s,OP>",yytext);}
{operator} {op++;printf("<%s,KEY>",yytext);}
. ;
%%

int main(int argc, char **argv){
    if(argc != 2){
        printf("usage: %s <filname>",argv[0]);
        exit(1);
    }

    yyin = fopen(argv[1],"r");

    yylex();

    printf("Identifiers:%d\nOperators:%d\nKeywords:%d\n",id,op,key);

}

int yywrap(){
    return 1;
}