#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"heap.h"


int main(){
    char number[128];
    int val;
    tree* start = NULL;
    printf("Enter numbers to add to tree. Enter 'p' to print tree.");
    printf("\nEnter 'd<value>' to remove from tree.\nEnter 'e' to exit\n");
    do{
        scanf("%s",number);
        switch(number[0]){
            case 'e': exit(0);
            case 'p':
            case 'P': 
                    if(start == NULL){
                        printf("Tree empty");
                        break;
                    }
                    printf("Post order:\n");
                    postOrder(start);
                    printf("Pre order:\n");
                    preOrder(start);
                    printf("In order:\n");
                    inOrder(start);
                    break;
            case 'd':
            case 'D':
            case 'r':
            case 'R':
                    val = atoi(number + 1);
                    if(deleteFromTree(start, val))
                        printf("Deleted\n");
                    else
                    {
                        printf("Not found\n");
                    }
                    break;
            case 'h':
                    printf("%d", treeHeight(start));
            case 'm':
                    printf("Max element: %d\n", findMax(start));
            default:
                    val = atoi(number);
                    start = insertAuto(start, val);
                    
        }
    }while(1);
    
}
