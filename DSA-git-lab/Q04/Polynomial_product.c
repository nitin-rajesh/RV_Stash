#include<stdio.h>
#include<stdlib.h>
#include"polystack.h"

stack* polyProd(stack* poly1, stack* poly2){
    //polyPrint(poly1);
    //polyPrint(poly2);
    stack *temp1 = poly1, *temp2;
    stack *polyAns = NULL;
    while(temp1 != NULL){
        temp2 = poly2;
        while(temp2 != NULL){
            polyAns = push(polyAns, (temp1->coeff)*(temp2->coeff),(temp1->exp) + (temp2->exp));
            //polyPrint(polyAns);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
        //printf("::");
        //polyPrint(temp1);
    }
    return polyAns;
}

stack* polyInput(int x){
    int exp;
    float coeff;
    stack* poly = NULL;
    printf("Enter variables of Polynomial %d in format coefficient:exponent\n", x);
    printf("Enter 0:0 when done\n");
    while(1){
        scanf("%f:%d", &coeff, &exp);
        if(coeff == 0 && exp == 0)
            break;
        poly = push(poly, coeff, exp);
    }
    return poly;
}

stack* polySort(stack* poly){
    //printf("In\n");
    stack *temp2 = poly;
    int tempExp; float tempCoeff;
    int len = length(poly);
    for(int i = 0; i < len; i++){
        temp2 = poly;
        //polyPrint(temp2);
        for(int j = 0; j < len - i - 1; j++){
            if(temp2->exp > temp2->next->exp){
                tempExp = temp2->exp;
                tempCoeff = temp2->coeff;
                temp2->exp = temp2->next->exp;
                temp2->coeff = temp2->next->coeff;
                temp2->next->exp = tempExp;
                temp2->next->coeff = tempCoeff;

            }
            //polyPrint(poly);
            temp2 = temp2->next;
        }
    }
    return poly;
}

stack* polyCompress(stack* poly){
    poly = polySort(poly);
    stack* newPoly = NULL;
    while(poly != NULL){
        if(newPoly == NULL){
            newPoly = push(newPoly, poly->coeff, poly->exp);
        }
        else if(newPoly->exp == poly->exp){
            newPoly->coeff = newPoly->coeff + poly->coeff;
        }
        else{
            newPoly = push(newPoly, poly->coeff, poly->exp);
        }
        poly = pop(poly);
        //polyPrint(newPoly);
    }
    return newPoly;
}

int main(){
    stack *poly1, *poly2, *polyAns;
    poly1 = polyInput(1);
    poly2 = polyInput(2);
    polyAns = polyProd(poly1, poly2);
    polyAns = polyCompress(polyAns);
    polyPrint(polyAns);
}