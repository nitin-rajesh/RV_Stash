%{
    #include<stdio.h>
    #include<stdlib.h>

    int yylex(void);
    void yyerror(char*);
%}

%token INTEGER NEWLINE;

%%
S: E NEWLINE {printf("%d\n",$1); return 0;}
;
E: E '+' T {$$ = $1 + $3;}
|E '-' T {$$ = $1 - $3;}
|T
;
T: T '*' P {$$ = $1 * $3;}
|T '/' P {$$ = $1 / $3;}
|P
;
P: '(' E ')' {$$ = $2;}
|INTEGER {$$ = $1;}
;
%%

int main(){
    printf("Enter expression\n");
    yyparse();
    return 0;
}

void yyerror(char *s){
    printf("%s",s);
}