#ifndef SPARSELIST
#define SPARSELIST


typedef struct Stack{
    int x;
    int y;
    int val;
    struct Stack* next;
    struct Stack* prev;
}sparselist;

sparselist* push_back(sparselist* top, int x, int y, int val){
    sparselist *temp = (sparselist*)malloc(sizeof(sparselist));
    ///temp->val = (int)val;
    temp->x = x;
    temp->y = y;
    temp->val = val;
    if(top == NULL){
        top = (sparselist*)malloc(sizeof(sparselist));
        top->val = 1;
        top->x = x;
        top->y = y;
        top->next = temp;
        temp->next = top;
        temp->prev = top;
    }
    else{
        sparselist *lastnode = top->next;
        while(lastnode->next != top){
            lastnode = lastnode->next;
        }
        lastnode->next = temp;
        temp->next = top;
        temp->prev = lastnode;
        top->val++;
        if(temp->x > top->x)
            top->x = temp->x;
        if(temp->y > top->y)
            top->y = temp->y;
    }
    return top;
}

sparselist* push_front(sparselist* top, int x, int y, int val){
    sparselist *temp = (sparselist*)malloc(sizeof(sparselist));
    ///temp->val = (int)val;
    temp->x = x;
    temp->y = y;
    temp->val = val;
    if(top == NULL){
        top = (sparselist*)malloc(sizeof(sparselist));
        top->val = 1;
        top->x = x;
        top->y = y;
        top->next = temp;
        temp->next = top;
        temp->prev = top;
    }
    else{
        temp->next = top->next;
        temp->prev = top;
        top->next = temp;
        top->val++;
        if(temp->x > top->x)
            top->x = temp->x;
        if(temp->y > top->y)
            top->y = temp->y;
    }
    return top;
}

/*sparselist* pop(sparselist* top){
    if(top == NULL){
        printf("Stack empty\n");
        return top;
    }
    //printf("Popped: %d\n",top->data);
    sparselist* temp = top;
    top = top->next;
    free(temp);
    return top;
}*/


int length(sparselist* st){
    int len = st->val;
    return len;
}

sparselist* searchList(sparselist* start, int x, int y){
    sparselist* node = start->next;
    while(node != start){
        if(node->x == x && node->y == y)
            return node;
        node = node->next;
    }
    return NULL;
}

void print_list(sparselist* st){
    sparselist* temp = st->next;
    /*while(temp->val == 0){
        temp = temp->next;
    }*/
    while(temp != st){
        printf("%d->", temp->val);
        temp = temp->next;
    }
    printf("\n");
}
  
#endif /*INTEGERLIST*/