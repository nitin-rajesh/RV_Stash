#ifndef INTEGERLIST
#define INTEGERLIST


typedef struct Stack{
    int val;
    struct Stack* next;
}intlist;

intlist* push_back(intlist* top, int val){
    intlist *temp = (intlist*)malloc(sizeof(intlist));
    ///temp->val = (int)val;
    temp->val = val;
    if(top == NULL){
        top = (intlist*)malloc(sizeof(intlist));
        top->val = 1;
        top->next = temp;
        temp->next = top;
    }
    else{
        intlist *lastnode = top->next;
        while(lastnode->next != top){
            lastnode = lastnode->next;
        }
        lastnode->next = temp;
        temp->next = top;
        top->val++;
    }
    return top;
}

intlist* push_front(intlist* top, int val){
    intlist *temp = (intlist*)malloc(sizeof(intlist));
    ///temp->val = (int)val;
    temp->val = val;
    if(top == NULL){
        top = (intlist*)malloc(sizeof(intlist));
        top->val = 1;
        top->next = temp;
        temp->next = top;
    }
    else{
        temp->next = top->next;
        top->next = temp;
        top->val++;
    }
    return top;
}

/*intlist* pop(intlist* top){
    if(top == NULL){
        printf("Stack empty\n");
        return top;
    }
    //printf("Popped: %d\n",top->data);
    intlist* temp = top;
    top = top->next;
    free(temp);
    return top;
}*/


int length(intlist* st){
    int len = st->val;
    return len;
}

void print_num(intlist* st){
    intlist* temp = st->next;
    /*while(temp->val == 0){
        temp = temp->next;
    }*/
    while(temp != st){
        if(temp->val < 0){
            if(temp == st->next)
            printf("-");
            printf("%d",temp->val * -1);
            temp = temp->next;
            continue;
        }
        printf("%d", temp->val);
        temp = temp->next;
    }
    printf("\n");
}
  
#endif /*INTEGERLIST*/