#include<stdio.h>

int main(){
    int process, resources;
    int i,j,k = 0, count1 = 0, count2 = 0;
    printf("Enter number of processes\n");
    scanf("%d",&process);
    printf("Enter number of resources\n");
    scanf("%d",&resources);
    int max[process][resources],allocated[process][resources],
    need[process][resources], available[resources], completed[process], 
    resource_instance[resources];

    printf("Enter the resource instance\n");
    for(i = 0; i < resources; i++)
        scanf("%d",&resource_instance[i]);

    for(i = 0; i < process; i++)
        completed[i] = 0;

    for(i = 0; i < resources; i++)
        available[i] = 0;

    printf("Enter max resource instance requirement...\n");
    for(i = 0; i < process; i++){
        printf("for process %d\n",i);
        for(j = 0; j < resources; j++){
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter allocated matrix...\n");
    for(i = 0; i < process; i++){
        printf("for process %d\n",i);
        for(j = 0; j < resources; j++){
            scanf("%d", &allocated[i][j]);
        }
    }

    for(i = 0; i < process; i++){
        for(j = 0; j < resources; j++){
            need[i][j] = max[i][j] - allocated[i][j];
        }
    }
    for(i = 0; i < resources; i++){
        for(j = 0; j < process; j++){
            available[i] = available[i] + allocated[j][i];
        }
    }

    for(i = 0; i < resources; i++){
        for(j = 0; j < process; j++){
            available[i] = resource_instance[i] - available[i];
        }
    }

    while(count1 != process){
        count2 = count1;
        for(i = 0; i < process; i++){
            for(j = 0; j < resources; j++){
                if(need[i][j] <= available[j])
                    k++;
            }
            if(k == resources && completed[i] == 0){
                completed[i] = 1;
                for(j = 0; j < resources; j++)
                    available[j] = allocated[i][j] + available[j];
                    printf("P[%d] ", i);
                    count1++;
            }
        k = 0;
        }
        printf("%d %d ", count1, count2);
        if(count1 == count2){
            printf("Not safe - Deadlock");
            break;
        }
    }
}