#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY
#define size arr[0]
#include<stdlib.h>

static int maxSize = 1;
//34 19 12 5 7 10
int* init(){
    int* arr = (int*)malloc(sizeof(int)*2);
    size = 0;
    maxSize++;
    return arr;
}
int* pushBack(int* arr, int val){
    if(arr == NULL)
        arr = init();
    if(size >= maxSize){
        maxSize = maxSize * 2;
        arr = (int*)realloc(arr, maxSize * sizeof(int));
    }
    size++;
    arr[size] = val;
    return arr;
}
int popBack(int* arr){

    if(size == 0){
        return 0;
    }
    size--;
    return arr[size+1];
}
int arrSize(int* arr){
    return size;
}
int popFront(int* arr){
    if(size == 0 || arr == NULL){
        return 0;
    }
    int temp = arr[1];
    for(int i = 2; i <= size; i++){
        arr[i-1] = arr[i];
    }
    size--;
    return temp;
}

#endif



