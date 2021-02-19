#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define len 256

typedef struct Queue{
    int front;
    int rear;
    char *word[];
}queue;

int is_full(queue message){
    if((message.rear+1)%len == message.front){
        return 1;
    }
    return 0;
}


int push_back(queue message, char* word){
    message.word[message.rear] = (char*)malloc(strlen(word)+10);
    strcpy(message.word[message.rear],word);
    if((message.rear+1)%len == message.front){
        printf("Queue full\n");
    }
    message.rear = (message.rear + 1) % len;
    return message.rear;
}

int pop_front(queue message){
    if(message.rear == message.front){
        printf("Queue empty\n");
        return message.front;
    }
    printf("Message: %s", message.word[message.front]);
    free(message.word[message.front]);
    message.front = (message.front + 1) % len;
    return message.front;
}

void traverse(queue message){
    while(message.front != message.rear){
        printf(">%s", message.word[message.front]);
        message.front = (message.front + 1)%(len+1);
    }
    printf(">END\n");
}

int main(){
    queue message;
    int guide;
    message.front = message.rear = 0;
    char word[128];
    printf("Message message\n");
    printf("1 Send\n");
    printf("2 Recieve\n");
    printf("3 Traverse\n");
    printf("4. Exit\n");
    //message.rear = push_back(message, "Lol", message.rear);
    //message.rear = push_back(message, "Yolo", message.rear);
    //traverse(message,message.front,message.rear);
    do{
        scanf("%d",&guide);
        switch(guide){
            case 1: 
                    if(is_full(message)){
                        printf("Queue full\n");
                    }
                    else{
                        printf("~");
                        fflush(stdin);
                        fgets(word, 128, stdin);
                        //scanf("%[^\n]s", word);
                        //printf("%s", word);
                        message.rear = push_back(message, word);
                        break;
                    }
                    
            case 2: 
                    message.front =  pop_front(message);
                    break;
            case 3:
                    traverse(message);
                    break;
            default:
                    fflush(stdin);
        }
    }while(guide != 4);
}
