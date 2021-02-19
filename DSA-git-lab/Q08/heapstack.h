#ifndef HEAPSTACK
#define HEAPSTACK
#include"heap.h"

typedef struct HeapStack{
    //int val;
    tree* op;
    struct HeapStack* next;
}heapstack;

heapstack* heapPush(heapstack* top, tree* val){
    heapstack* temp = (heapstack*)malloc(sizeof(heapstack));
    ///temp->val = (int)val;
    temp->op = (tree*)val;
    temp->next = top;
    top = temp;
    return top;
}

heapstack* heapPop(heapstack* top){
    if(top == NULL){
        printf("heapstack empty\n");
        return top;
    }
    //printf("Popped: %d\n",top->data);
    heapstack* temp = top;
    top = top->next;
    return top;
}

int heapLength(heapstack* st){
    int len = 0;
    while(st != NULL){
        st = st->next;
        len++;
    }
    return len;
}

tree* heapTop(heapstack* st){
    return st->op;
}

#endif /*TREESTACK*/