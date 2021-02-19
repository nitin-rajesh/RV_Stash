#include<stdio.h>
#define TABLE_SIZE 20

void display(int hashTable[]){

    for(int i=0;i< TABLE_SIZE; i++)

    printf("Index %d::\t%d\n",i,hashTable[i]);

}

int hash2(int key){
    return 7 - (key%7);
}

void insert(int hashTable[], int key){

    int index,i,flag=0,hkey;
    hkey=key%TABLE_SIZE;
    for(i=0;i<TABLE_SIZE;i++){
        //Using double hashing. Change the below line to the required hashing algo
        index=(hkey+i*hash2(key))%TABLE_SIZE;

        if(hashTable[index] ==-1)
        {
        hashTable[index]=key;
            break;
        }
    }
    if(i == TABLE_SIZE)
    printf("Element cannot be inserted\n");
}

int search(int hashTable[], int key){

    int index,i,flag=0,hkey;
    hkey=key%TABLE_SIZE;
    for(i=0;i<TABLE_SIZE; i++)
    {
        //Using double hashing. Change the below line to the required hashing algo
        index=(hkey+i*hash2(key))%TABLE_SIZE;
        if(hashTable[index]==key)
        {
            return index;
        }
    }
        return -1;
}

void delete(int hashTable[], int val ){
    int pos;
    pos = search(hashTable, val);
    if (pos ==-1)
        printf("Element not found \n");
    else{
      hashTable[pos]= -1;
      printf("%d is deleted \n ",val);
    }
}

int main(){

    int hashTable[TABLE_SIZE];
    int s,k,v;
    char op;
    for (int i= 0; i< TABLE_SIZE;i++)
       hashTable[i] =-1;
    
    printf("Enter i. Insert\t p. Display \ts. Search \td.Delete \ne. Exit \n");

    do{
        scanf("%c",&op);
        switch(op){
            case 'i': 
                    scanf("%d",&k);
                    insert(hashTable, k);
                    break;
                    
            case 'p': display(hashTable);
                    break;
                    
            case 's':
                   scanf("%d",&k);
                   s= search(hashTable, k);
                   if (s==-1)
                    printf("Element not found \n");
                   else 
                    printf("Value is found at Index %d\n",s);
                   break;
                   
            case 'd': 
                    scanf("%d",&v);
                    delete(hashTable, v);
                    break;
        }
    }while(op != 'e');
}


