#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>


/*Program creates a set number of random numbers within 
a certain range and sorts them using bubble sort */

int main(int argc,  const char* argv[]){
    //printf("I am here\n");
    int len, range;
    len = atoi(argv[1]);
    range = atoi(argv[2]);
    int arr[len];
    int count[range];
    for(int i = 0; i < range; i++)
    	count[i] = 0;
    srand(time(0));
    //printf("I got here\n");
    for(int i = 0; i < len; i++){
        arr[i] = rand()%range;
	count[arr[i]]++;
    }

    /*for(int i = 0; i < len; i++)
        for(int j = 0; j < len - i - 1; j++){
            if(arr[j]>arr[j+1]){
                range = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = range;
            }
        }
	*/
    for(int i = 0; i < len; i++){
        printf("%d\t",arr[i]);
        if((i+1)%10 == 0){
            printf("\n");
        }
    }
    printf("\nCount\n");
    for(int i = 0; i < range; i++){
    	printf("%d:: %d\n",i,count[i]);
    }

}
