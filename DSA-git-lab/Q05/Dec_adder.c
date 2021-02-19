#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"integerlist.h"
#define INT_LIMIT 9

intlist* inputList(intlist* start){
    //int netVal = 0;
    char temp;
    do{
        temp = getchar();
        if(temp == '-')
            printf("Only handles positive. Taking absolute value\n");
            //signint = -1;
        if(!isdigit(temp))
            continue;
        start = push_back(start, (temp - 48));
    }while(temp != '\n');
    //printf("%d\t",netVal);
    //start = push_back(start, netVal%(INT_LIMIT + 1));
    //print_num(start);
    if(start == NULL)
        push_back(start, 0);
    return start;
}

intlist* conformList(intlist* numList){
    //print_num(numList);
    intlist* place;
    int carry = 0, borrow = 0;
    for(int i = length(numList); i > 0; i--){
        place = numList->next;
        for(int j = i; j > 1; j--){
            place = place->next;
        }
        place->val = place->val + carry;
        carry = place->val / 10;
        place->val = place->val % 10;
    }
    place = numList->next;
    for(int i = length(numList); i >= 0; i--){
        if(place->next->val){
            if(place->next->val < 0 && place->val > 0){
                place->next->val = place->next->val + 10;
                place->val--;
            }
            if(place->next->val > 0 && place->val < 0){
                place->next->val = place->next->val - 10;
                place->val++;
            }
        }
        place = place->next;
    }
    if(carry != 0){
        push_front(numList, carry);
    }
    return numList;
}

intlist* addList(intlist* num1, intlist* num2){

    intlist *sum = NULL, *maxNum, *minNum;
    int len1 = length(num1);
    int len2 = length(num2);
    int maxLen, minLen;
    if(len1 < len2){
        maxLen = len2;
        minLen = len1;
        maxNum = num2;
        minNum = num1;
    }
    else
    {
        maxLen = len1;
        minLen = len2;
        maxNum = num1;
        minNum = num2;
    }
    //make the number of elements equal in both lists
    //then add the lists
    printf("  ");
    print_num(maxNum);
    for(int i = 0; i < maxLen - minLen; i++){
        printf(" ");
    }
    if(minNum > 0)
        printf("+ ");
    print_num(minNum);
    for(int i = 0; i < maxLen - minLen; i++){
        minNum = push_front(minNum,0);
    }
    
    //print_num(num1);
    //print_num(num2);
    maxNum = num1->next;
    minNum = num2->next;
    for(int i = 0; i < maxLen; i++){
        sum = push_back(sum, maxNum->val + minNum->val);
        maxNum = maxNum->next;
        minNum = minNum->next;
    }
    sum = conformList(sum);
    return sum;
}

int main(){
    intlist *bigNum1 = NULL, *bigNum2 = NULL, *bigNumSum = NULL;
    printf("Enter the first number: ");
    bigNum1 = inputList(bigNum1);
    printf("Enter the second number: ");
    bigNum2 = inputList(bigNum2);
    printf("\n");
    bigNumSum = addList(bigNum1, bigNum2);
    for(int i = 0; i <= length(bigNumSum)+1; i++)
        printf("_");
    printf("\n=");
    if(length(bigNumSum) == length(bigNum1) || length(bigNumSum) == length(bigNum2))
        printf(" ");
    print_num(bigNumSum);
    printf("\n");
}