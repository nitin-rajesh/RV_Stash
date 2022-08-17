%{
    #include<stdio.h>
    #include<stdlib.h>

    int yylex(void);    
    void yyerror(char*);

    int fn_defs = 0;

%}

%token ID INFIX UNARY LITERAL KEYWORD

%%
program:
    statement_set {printf("%d functions",fn_defs); exit(0);}
;

statement_set:
    expression ';' statement_set
    |fn_block {fn_defs++;} statement_set
    |
;

fn_block:
    KEYWORD ID '(' param_list ')' '{' statement_set '}' {printf("//function defined\n");}
;

param_list:
    params
    |
;

params:
    KEYWORD ID ',' params
    |KEYWORD ID
;

expression:
    operand expression
    |KEYWORD expression 
    | operand INFIX expression
    | UNARY expression
    | '(' expression ')'
    | operand
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