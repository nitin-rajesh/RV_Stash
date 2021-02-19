#ifndef CHARSTACK
#define CHARSTACK


typedef struct Stack{
    //int val;
    char op;
    struct Stack* next;
}charstack;

charstack* push(charstack* top, char val){
    charstack* temp = (charstack*)malloc(sizeof(charstack));
    ///temp->val = (int)val;
    temp->op = (char)val;
    temp->next = top;
    top = temp;
    return top;
}

charstack* pop(charstack* top){
    if(top == NULL){
        printf("Stack empty\n");
        return top;
    }
    //printf("Popped: %d\n",top->data);
    charstack* temp = top;
    top = top->next;
    free(temp);
    return top;
}

int length(charstack* st){
    int len = 0;
    while(st != NULL){
        st = st->next;
        len++;
    }
    return len;
}

char top(charstack* st){
    return st->op;
}

#endif /*CHARSTACK*/