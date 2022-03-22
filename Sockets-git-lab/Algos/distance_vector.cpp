#include<iostream>
#include<fstream>
using namespace std;

class node{
public:
    int *distance;
    int *from;
    int size;

    node(int size){
        this->size = size;
        distance = new int[size];
        from = new int[size];
    }

    ~node(){
        delete distance;
        delete from;
    }
};

class DVR{
    int ** graph;
    int vertices;
    node** routeTable;

public:
    static const int inf = 9999;

    void constructTable(int *graph[]){
        for(int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices; j++){
                routeTable[i]->distance[j] = graph[i][j];
                routeTable[i]->from[j] = j;
            }
        }
    }

    void initGraph(int *a[]){
        for(int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices; j++){
                if(i == j){
                    graph[i][j] = 0;
                }
                else{
                    graph[i][j] = a[i][j];
                }
                cout<<graph[i][j]<<'\t';
            }
            cout<<endl;
        }
        constructTable(graph);

    }

    void buildDVR(){
        int count;
        do{
            count = 0;
            for(int i = 0; i < vertices; i++){
                for(int j = 0; j < vertices; j++){
                    for(int k = 0; k < vertices; k++){
                        if(routeTable[i]->distance[j] 
                            > graph[i][k] + routeTable[k]->distance[j]){

                            //calculate minimum distance
                            routeTable[i]->distance[j] = routeTable[i]->distance[k] 
                                + routeTable[k]->distance[j];

                            cout<<i<<':'<<j<<'\t'<<routeTable[i]->distance[j]<<endl;
                            
                            routeTable[i]->from[j] = k;
                            count++;
                        }
                    }
                }
            }
        }while(count != 0);
    }

    void printTable(){
        for(int i = 0; i < vertices; i++){
            cout<<"For router "<<i+1<<endl;
            for(int j = 0; j < vertices; j++){
                cout<<"Node "<<j+1
                    <<" via "<<routeTable[i]->from[j] + 1
                    <<" distance "<<routeTable[i]->distance[j]
                    <<endl;
            }
            cout<<endl;
        }
    }

    DVR(int size){
        vertices = size;
        graph = new int*[size];
        for(int i = 0; i < size; i++)
            graph[i] = new int[size];


        routeTable = new node*[size];
        for(int i = 0; i < size; i++)
            routeTable[i] = new node(size);
    }

    ~DVR(){

    }

};

int main(){
    int x[] = {0, 1, 5, DVR::inf, DVR::inf};
    int y[] = {1, 0, 3, DVR::inf, 9};
    int z[] = {5, 3, 0, 4, DVR::inf};
    int u[] = {DVR::inf, DVR::inf, 4, 0, 2};
    int v[] = {DVR::inf, 9, DVR::inf, 2, 0};

    int *a[] = {x,y,z,u,v};

    DVR test(5);
    test.initGraph(a);
    test.buildDVR();
    test.printTable();
    
}