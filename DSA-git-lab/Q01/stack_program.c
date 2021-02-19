#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int data;
    struct Stack* next;
}stack;

stack* push(stack* top, int val){
    stack* temp = (stack*)malloc(sizeof(stack));
    temp->data = val;
    temp->next = top;
    top = temp;
    return top;
}

stack* pop(stack* top){
    if(top == NULL){
        printf("Stack empty\n");
        return top;
    }
    printf("Popped: %d\n",top->data);
    stack* temp = top;
    top = top->next;
    free(temp);
    return top;
}

void display(stack* top){
    if(top == NULL)
        printf("Stack empty\n");
    while(top != NULL){
        printf("%d -> ", top -> data);
        top = top->next;
    }
    printf("END\n");
}

int alg1(stack *top){
    if(top == NULL){
        display(top);
    }
    for(int i = 1; (i < 3) && (top != NULL); i++){
        top = top->next;
        if(top == NULL){
            display(top);
            return 0;
        }
    }
    return top->data;
}

stack* alg2(stack* top, int n){
    for(int i = 0; i < n; i++){
        top = pop(top);
        if(top == NULL)
            return top;
    }
    return top;
}

int alg3(stack* top){
    stack* temp = top;
    int size = 0;
    while(temp != NULL){
        temp = temp->next;
        size++;
    }
    for(int i = 0; (i < size - 3) && (top != NULL); i++){
        top = top->next;
        if(top==NULL){
            display(top);
            return 0;
        }
    }
    return top->data;
}

int main(){

int ch, y, n, x;
stack* s = NULL;
    while(1)
    {
        printf("\n\t1:PUSH 2:POP 3:TOP-3 4:POP-N 5:BOTTOM-3 6:DISPLAY 7:EXIT\n");
        printf( "\n\tEnter Choice: ");
        scanf("%d", &ch);

        switch( ch ) 
        {
        case 1: printf("\nEnter x :");
        scanf("%d", &x);
        s = push(s, x);
        break;
        case 2: s = pop( s );
        //printf("\t%d : poped\n", y);
        break;
        case 3: printf("%d\n",alg1( s ));
        break;
        case 4: printf("Enter no. of elements to be poped\n");
        scanf("%d", &n);
        s = alg2( s, n);
        break;
        case 5: printf("%d\n",alg3( s ));
        break;
        case 6: display( s );
        break;
        case 7: exit(0);

        }
    }
    return 0;
}
    /*stack *top = NULL;
    int q, val;
    scanf("%d",&q);
    while(q > 0){
        scanf("%d",&val);
        top = push(top,val);
        q--;
    }
    /*top = push(top,2);
    top = push(top,3);
    top = push(top,5);
    top = push(top,7);
    top = push(top,11);

    //q1
    stack* temp = top;
    temp = temp->next->next;
    printf("%d\n", temp->data);

    //q2
    scanf("%d",&q);
    for(int i = 0; i < q && top != NULL; i++){
        top = pop(top);
    }

    //q3
    int size = 0;
    temp = top;
    while(temp!=NULL){
        temp = temp->next;
        size = size + 1;
    }
    temp = top;

    for(int i = 0; i < (size - 3) && temp != NULL; i++){
        temp = temp->next;
    }
    printf("%d", temp->data);*/