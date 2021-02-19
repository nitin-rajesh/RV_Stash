#ifndef POLYSTACK
#define POLYSTACK


typedef struct Stack{
    //int val;
    float coeff;
    int exp;
    struct Stack* next;
}stack;

stack* push(stack* top, float coeff, int exp){
    stack* temp = (stack*)malloc(sizeof(stack));
    //temp->val = (int)val;
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = top;
    top = temp;
    return top;
}

stack* pop(stack* top){
    if(top == NULL){
        printf("Stack empty\n");
        return top;
    }
    //printf("Popped: %d\n",top->data);
    stack* temp = top;
    top = top->next;
    free(temp);
    return top;
}

int length(stack* st){
    int len = 0;
    while(st != NULL){
        st = st->next;
        len++;
    }
    return len;
}

void polyPrint(stack* st){
    while(st != NULL){
        if(st->coeff != (float)0){
            if(st->exp == 0){
                printf("%0.2f",st->coeff);
            }
            else if(st->exp == 1){
                printf("%0.2fx",st->coeff);
            }
            else{
                printf("%0.2fx^%d", st->coeff, st->exp);
            }
            if(st->next){
                if(st->next->coeff >=x (float)0)
                    printf(" +");
                else{
                   printf(" ");
                }
            }     
        }
        st = st->next;
    }
    printf("\n");
}

#endif /*POLYSTACK*/