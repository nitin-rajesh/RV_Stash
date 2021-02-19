#ifndef STRSTACK
#define STRSTACK
#include<stdio.h>
#include<string.h>

typedef struct Stack{
    //int val;
    char op[128];
    struct Stack* next;
}charstack;

charstack* push(charstack* top, char* word){
    charstack* temp = (charstack*)malloc(sizeof(charstack));
    ///temp->val = (int)val;
    strcpy(temp->op,word);
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

void traverse(charstack* st){
    charstack* node = st;
    if(st == NULL){
        printf("Queue empty");
        return ;
    }
    do{
        printf("%s",node->op);
        node = node->next;
    }while(node!=st);
}

#endif /*STRSTACK*/