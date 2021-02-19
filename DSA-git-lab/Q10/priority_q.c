#include<stdio.h>
#include<stdlib.h>
#include"dynamic_array.h"

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void conformArr(int* q){
    //printf("%d",arrSize(q));
    if(arrSize(q) <= 1 || q == NULL){
        return ;
    }
    for(int j = arrSize(q); j > 0; j--){
        for(int i = j; i > 1; i = i/2){
            //printf("Node: %d\tParent: %d\n",q[i],q[i/2]);
            if(q[i] > q[i/2]){
                swap(&q[i], &q[i/2]);
                //printf("Swapped\n");
            }
        }
    }
}

int* insertMax(int* q, int val){
    q = pushBack(q,val);
    conformArr(q);
    return q;
}

void delMax(int* q){
    printf("%d removed\n", popFront(q));
    conformArr(q);
}

void delVal(int* q, int n){
    for(int i = 0; i < arrSize(q); i++){
        if(q[i] == n){
            popBack(q);
            q[i] = -9999;
            printf("%d removed\n", n);
        }
    }
    conformArr(q);
}

void display(int* q){
    if(q == NULL)
        return ;
    for(int i = 1; i <= arrSize(q); i++){
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main(){
    int* priorityQueue = init();
    int k;
    char op[32];
    printf("Enter numbers to insert\nUse alphabet:\n\t p. Display \td.Delete \tm. Pop max\te. Exit \n");
    do{
        scanf("%s",op);
        switch(op[0]){
                    
            case 'p': display(priorityQueue);
                    break;
                   
            case 'd': 
                    scanf("%d",&k);
                    delVal(priorityQueue, k);
                    break;
            case 'm':
                    delMax(priorityQueue);
                    break;
            default:
            case 'i': 
                    k = atoi(op);
                    priorityQueue = insertMax(priorityQueue, k);
                    break;
        }
    }while(op[0] != 'e');
}