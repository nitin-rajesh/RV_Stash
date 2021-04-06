#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
#include<chrono>
using std::vector;
using std::cout;
using std::swap;
using std::endl;

class Sorting{
protected:
    vector<int> array;
    double timeSpent;
    int iterationCount;
    virtual void sortMe() = 0;
public:
    void init(int len, int range = 1000){
        array.clear();
        timeSpent = 0;
        iterationCount = 0;
        srand(time(0));
        for(int i = 0; i < len; i++){
            array.push_back(rand()%range);
        }

    }
    void initBest(int len, int range = 1000){
        array.clear();
        timeSpent = 0;
        iterationCount = 0;
        for(int i = 0; i < len; i++){
            array.push_back(i);
        }

    }
    void initWorst(int len, int range = 1000){
        array.clear();
        timeSpent = 0;
        iterationCount = 0;
        for(int i = 0; i < len; i++){
            array.push_back(range - i);
        }

    }
    void sortArray(){
        std::chrono::steady_clock::time_point _start(std::chrono::steady_clock::now());
        sortMe();
        std::chrono::steady_clock::time_point _end(std::chrono::steady_clock::now());
        timeSpent = std::chrono::duration_cast<std::chrono::duration<double> >(
                        _end - _start).count();
    }
    void printArray(){
        for(int i = 1; i <= array.size(); i++){
            cout<<array[i]<<'\t';
            if(i%10 == 0){
                cout<<endl;
            }
        }
        cout<<endl;
    }
    int comparisons(){
        return iterationCount;
    }
    double sortingTime(){
        return timeSpent;
    }
    Sorting(){
        iterationCount = 0;
        timeSpent = 0;
    }
    Sorting(int len){
        iterationCount = 0;
        timeSpent = 0;
        init(len);
    }
    Sorting(int len, int range){
        iterationCount = 0;
        timeSpent = 0;
        init(len, range);
    }
    virtual ~Sorting(){
        array.clear();
    }
};