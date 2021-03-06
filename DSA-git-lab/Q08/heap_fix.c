#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include"heapstack.h"
#include"charstack.h"

void charcat(char* str, char c){
    if(c == '('||c == ')'){
        return ;
    }
    //return ;
    int l = strlen(str);
    //return ;
    str[l] = c;
    return ;
}

int prec(char c)
{
    if(c == '$' || c == '^')
    return 4;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else if(c == '(' || c == '[' ||  c == '{')
    return 0;
    else if(c == ')' || c == ']' || c == '}')
    return -1;
    else
    return -2;
}

char* infixToPostfix(char* s)
{
    charstack* st = NULL;
    int l = strlen(s);
    char ns[128] = "";
    for(int i = 0; i < l; i++)
    {
         

        if(isalnum(s[i]))
            charcat(ns,s[i]);

        else if(s[i] == '(')
         
        st = push(st,'(');

        else if(s[i] == ')')
        {
            while(st != NULL && st->op != '(')
            {
                char c = st->op;
                st = pop(st);
               charcat(ns,c);
            }
            if(st->op == '(')
            {
                char c = st->op;
                st = pop(st);
            }
            //if(st->op == NULL && )
        }

        else{
            while(st != NULL && prec(s[i]) <= 
                                   prec(st->op))
            {
                char c = st->op;
                st = pop(st);
                charcat(ns,c);
            }
            st = push(st,s[i]);
        }
 
    }
    while(st != NULL)
    {
        char c = st->op;
        st = pop(st);
        charcat(ns,c);
    }
     
    //printf("%s",ns);
    strcpy(s,ns);
    return s;
}
 
//Driver program to test above functions

char* checkExpression(char* exp){
    int x = strlen(exp);
    int isPow = 0;
    int y;
    char c;
    char* newExp = (char*)malloc(2*x);
    char* temp = newExp;
    char * checkC;
    charstack* st = NULL;
    for(int i = 0; i < x; i++){
        //printf("%c",exp[i]);
        if(exp[i] != ' ')
            *temp++ = exp[i];
        if(!isalnum(exp[i])){
            if(exp[i] == ' '){
                continue;
            }
            if(i==0){
                if(prec(exp[i]) != 0){
                    printf("Error in expression");
                    exit(0);
                }
                
            }
            y = prec(exp[i]);

            switch(y){
                case 4:
                        isPow = 1;
                        *temp++ = '(' ;
                        break;
                case 0:

                        st = push(st, exp[i]); 
                        *(temp - 1) = '(';
                        //printf("Pushed");
                        break;
                case -1:
                        *(temp - 1) = ')';
                        if(st == NULL){
                            printf("Extra brackets");
                            exit(0);
                        }
                        c = st->op;
                        st = pop(st);
                        if(c == exp[i] - 1 || c == exp[i] - 2)
                            continue;
                        else
                        {
                            printf("Mismatched brackets");
                            exit(0);
                        }
                        break;
                case -2:
                        printf("Unrecognised operator");
                        exit(0);
                        break;
                default:
                        if(prec(*(temp-2)) > 0){
                            printf("Operator mismatch");
                            exit(0);
                        }
                        if(isPow){
                            *temp = *(temp-1);
                            *(temp-1) = ')';
                            temp++;
                            isPow = 0;
                        }

            }
        }
    }
    if(st != NULL){
        printf("Mismatched brackets");
            exit(0);
    }
    *temp = '\0';
    free(exp);
    return newExp;
}

tree* constructTree(char postfix[]){
	heapstack* st = NULL;
	tree *t1 = NULL, *t2 = NULL;

	// Traverse through every character of
	// input expression
	for (int i=0; i<strlen(postfix); i++)
	{
		// If operand, simply push into stack
		if (prec(postfix[i]) < 1)
		{
			tree* temp = NULL;
            temp = initNode(temp, (int)postfix[i]);
			st = heapPush(st, temp);
		}
		else // operator
		{
			tree* temp = NULL;
            temp = initNode(temp, postfix[i]);
			// Pop two top nodes
			t1 = heapTop(st); // Store top
			st = heapPop(st);	 // Remove top
			t2 = heapTop(st);
			st = heapPop(st);
			// make them children
			insertRightNode(temp, t1);
            insertLeftNode(temp, t2);
			// Add this subexpression to stack
			st = heapPush(st, temp);
		}
	}

	// only element will be root of expression
	// tree

	return st->op;
	
}

int main(){
    tree* heap = NULL;
    char* exp = malloc(128);
    scanf("%[^\n]s",exp);
    exp = checkExpression(exp);
    exp = infixToPostfix(exp);
    heap = constructTree(exp);
    printf("Infix:   ");
    inOrder(heap);
    printf("Postfix: ");
    postOrder(heap);
    printf("Prefix:  ");
    preOrder(heap);
}