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
    char tempVar = '0';

    char appendToTable(char opd1, char opd2, char opr);
    void threeAddressCode();
    char* formatStr(char);


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

    tempVar = '0';


    printf("\nASM\n");
    for(int count = 0; count < indexVal; count++){
        switch(tacStack[count].opr){
            case '=': printf("STR  %c,  %s\n",tacStack[count].opd1,formatStr(tacStack[count].opd2));
            break;
            case '+': printf("ADD  %s, %s,  %s\n",formatStr(tempVar++),formatStr(tacStack[count].opd1),formatStr(tacStack[count].opd2));
            break;
            case '-': printf("SUB  %s,  %s,  %s\n",formatStr(tempVar++),formatStr(tacStack[count].opd1),formatStr(tacStack[count].opd2));
            break;
            case '*': printf("MUL  %s,  %s,  %s\n",formatStr(tempVar++),formatStr(tacStack[count].opd1),formatStr(tacStack[count].opd2));
            break;
            case '/': printf("DIV  %s,  %s,  %s\n",formatStr(tempVar++),formatStr(tacStack[count].opd1),formatStr(tacStack[count].opd2));
            break;
        }
    }

}

char appendToTable(char opd1, char opd2, char opr){
    tacStack[indexVal].opd1 = (opd1);
    tacStack[indexVal].opd2 = (opd2);
    tacStack[indexVal].opr = opr;
    indexVal++;
    return tempVar++;
}

char* formatStr(char val){
    char Rx[] = "Rx";
    Rx[1] = val;

    if(val >= '0' && val <= '9'){
        return strdup(Rx);
    }
    Rx[0] = '#';
    return strdup(Rx);
    
}


void yyerror(char *s){
    printf("%s",s);
    exit(0);
}
