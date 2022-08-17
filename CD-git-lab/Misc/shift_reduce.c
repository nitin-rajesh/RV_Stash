#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct RuleSet{
    char lhs[16];
    char rhs[32];
}ruleset;

void parse(ruleset *productions, int size, char *expression);
int searchProduction(ruleset *productions, int size, char *expression);
void reduce(char *stack, ruleset production);
void shift(char *stack, char *expression);
void printRuleSet(ruleset *productions, int size);

int main(){
    ruleset r1 = {
        .lhs = "E",
        .rhs = "E+E"
    },
    r2 = {
        .lhs = "E",
        .rhs = "E*E"
    },
    r3 = {
        .lhs = "E",
        .rhs = "E-E",
    },
    r4 = {
        .lhs = "E",
        .rhs = "i"
    };

    ruleset productions[] = {r1,r2,r3,r4};
    int size = 4;

    char expression[32];

    printRuleSet(productions,size);
    printf("\nEnter expression\n");
    scanf("%s",expression);

    parse(productions,size,expression);
    return 0;
}

void parse(ruleset *productions, int size, char *expression){
    char stack[64] = "";
    printf("Stack\tExp\tOp\n");
    printf("$%s\t%s$\t%s\n",stack,expression,"");
    while(strlen(expression)){
        int index = searchProduction(productions,size,stack);
        if(index == -1){
            printf("$%s\t%s$\t%s\n",stack,expression,"shift");
            shift(stack,expression);
        }
        else{
            printf("$%s\t%s$\t%s\n",stack,expression,"reduce");
            reduce(stack,productions[index]);
        }
    }  
    printf("$%s\t%s$\t%s\n",stack,expression,"Accept");
}

void shift(char *stack, char *expression){
    int size = strlen(stack);
    stack[size] = expression[0];
    stack[size+1] = '\0';
    for(int i = 0; i < strlen(expression); i++){
        expression[i] = expression[i+1];
    }
}

void reduce(char *stack, ruleset production){
    strcpy(stack,production.lhs);
}

int searchProduction(ruleset *productions, int size, char *expression){
    do{
        for(int i = 0; i < size; i++){
            if(strcmp(productions[i].rhs,expression) == 0)
                return i;
        }
    }while(*expression++ != '\0');
    return -1;
}

void printRuleSet(ruleset *productions, int size){
    printf("Rules:\n");
    for(int i = 0; i < size; i++){
        printf("%s->%s\n",productions[i].lhs,productions[i].rhs);
    }
}