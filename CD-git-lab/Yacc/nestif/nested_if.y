%{
    #include<stdio.h>
    #include<stdlib.h>

    int yylex(void);    
    void yyerror(char*);

    int if_statement = 0;

%}

%token ID INFIX UNARY LITERAL IF ELSE

%%
program:
    statement_set {printf("%d if statements",if_statement); exit(0);}
;

statement_set:
    expression ';' statement_set
    |for_block {if_statement++;} statement_set
    |
;

for_block:
    IF '(' expression ')' '{' statement_set '}'
    |IF '(' expression ')' '{' statement_set '}' ELSE '{' statement_set '}'
;

expression:
    operand INFIX expression
    |operand expression
    |operand UNARY
    |UNARY operand
    |
;

operand:
    LITERAL
    |ID
;
%%

int main(){
    yyparse();
}

void yyerror(char *s){
    printf("%s",s);
    exit(0);
}
