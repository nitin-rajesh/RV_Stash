#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* myThread(void *myvar){
    int len, range;
    len = *(int*)myvar;
    range = 6;
    int arr[len];
    int dice1, dice2;
    int count[2*range];
    for(int i = 0; i < 2*range; i++)
    	count[i] = 0;
    srand(time(0));
    //printf("I got here\n");
    for(int i = 0; i < len; i++){
        dice1 = rand()%range;
        dice2 = rand()%range;
        arr[i] = dice1 + dice2 + 2;
	    count[arr[i]]++;
    }
    printf("Rolling dice %d times...\n",len);
    for(int i = 0; i < len; i++){
        printf("%d\t",arr[i]);
        if((i+1)%10 == 0){
            printf("\n");
        }
    }
    printf("\nOccurences\n");
    for(int i = 2; i <= 2 * range; i++){
    	printf("%d:: %d\n",i,count[i]);
    }

    return NULL;
}

int main(int argc, const char *argv[]){
    int val = atoi(argv[1]);
    pthread_t thread_id;
    pthread_attr_t attribute;
    pthread_attr_init(&attribute);
    pthread_create(&thread_id, NULL, myThread, (void*)&val);
    for(int i = 0; i < 5; i++)
        pthread_join(thread_id, NULL);

}