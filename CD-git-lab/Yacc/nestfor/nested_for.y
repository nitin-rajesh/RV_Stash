%{
    #include<stdio.h>
    #include<stdlib.h>

    int yylex(void);    
    void yyerror(char*);

    int for_loops = 0;

%}

%token ID INFIX UNARY LITERAL FOR

%%
program:
    statement_set {printf("%d for loops",for_loops); exit(0);}
;

statement_set:
    expression ';' statement_set
    |for_block {for_loops++;} statement_set
    |
;

for_block:
    FOR '(' expression ';' expression ';' expression ')' '{' statement_set '}'
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
