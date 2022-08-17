%{
    #include<stdio.h>
    int yylex(void);
    void yyerror(char*);
%}

%%
S:F E;
F: 'a'F'b'|;
E: 'b'E'c'|;
%%

int main(){
    printf("Enter expression\n");
    yyparse();
    printf("Valid string\n");
}

void yyerror(char *s){
    printf("Invalid");
    exit(0);
}