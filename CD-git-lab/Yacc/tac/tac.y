%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>

    void yyerror(char *s);
    int yylex(void);

    typedef struct TACToken{
        char opd1;
        char opd2;
        char opr;
    } tacToken;

    tacToken tacStack[50];

    int indexVal = 0;
    char tempVar = 'A';

    char appendToTable(char opd1, char opd2, char opr);
    void threeAddressCode();


%}

%union {
    char sym;
}
%token <sym> ALPHA INTEGER
%type <sym> expression
%left '-' '+'
%right '*' '/'

%%
statement_set: 
    ALPHA '=' expression ';' {appendToTable((char)$1,(char)$3,'=');}
    |expression ';' {return 0;}
;

expression: 
    expression '+' expression {$$ = appendToTable((char)$1,(char)$3,'+');}
    |expression '-' expression {$$ = appendToTable((char)$1,(char)$3,'-');}
    |expression '*' expression {$$ = appendToTable((char)$1,(char)$3,'*');}
    |expression '/' expression {$$ = appendToTable((char)$1,(char)$3,'/');}
    |'(' expression ')' {$$ = $2;}
    |ALPHA {$$ = (char) $1;}
    |INTEGER {$$ = (char) $1;}
;
%%

int main(){
    printf("Enter expression\n");
    yyparse();
    threeAddressCode();
}

void threeAddressCode(){

    tempVar = 'A';
    printf("\nTAC\n");

    for(int count = 0; count < indexVal; count++){
        if(tacStack[count].opr != '=')
            printf("%c = ",tempVar++);

        printf("%c %c %c\n",tacStack[count].opd1,tacStack[count].opr,tacStack[count].opd2);
    }

}

char appendToTable(char opd1, char opd2, char opr){
    tacStack[indexVal].opd1 = (opd1);
    tacStack[indexVal].opd2 = (opd2);
    tacStack[indexVal].opr = opr;
    indexVal++;
    return tempVar++;
}

void yyerror(char *s){
    printf("%s",s);
    exit(0);
}
