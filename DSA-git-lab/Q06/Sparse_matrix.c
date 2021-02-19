#include<stdio.h>
#include<stdlib.h>
#include"sparselist.h"

void printMatrix(sparselist* start){
    if(start == NULL){
        printf("0");
        return ;
    }
    sparselist* node;
    for(int i = 1; i <= start->x; i++){
        for(int j = 1; j <= start->y; j++){
            node = searchList(start, i, j);
            if(node)
                printf("%d\t",node->val);
            else
            {
                    printf("0\t");
            }
            
        }
        printf("\n");
    }
}


int main(){
    sparselist* start = NULL;
    int x, y, val;
    printf("\n~Enter elements of sparse matrix in format <x coordinate>:<y coordinate>=<value>\n");
    printf("~To set a size for matrix, enter <max x>:<max y>=0. If no size is entered, then smallest fit is considered\n");
    printf("~In case of multiple entries to same coordinates, the last entry will be considered\n");
    printf("~Coordinates start from 1:1. Enter 0:0 to finish.\n");
    while(1){
        scanf("%d:%d=%d",&x,&y,&val);
        if(x <= 0 || y <= 0)
            break;
        start = push_front(start, x, y, val);
        printf("Accepted\n");
    }
    printf("Matrix: \n");
    printMatrix(start);
}