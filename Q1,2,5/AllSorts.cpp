#include"AllSorts.h"
#include"SortFunctions.h"
#include<math.h>
using std::vector;
using std::cout;
using std::swap;
using std::endl;

void TimeDiagnostics(Sorting *SortSession, int startvar = 64, int endvar = 4096){
    cout<<"Size\tAsc\tDesc\tRandom\tAvg time\tNext time predicted\n";
    double avgtime = 0;
    double prev_avgtime = 0;
    for(int i = startvar; i <= endvar; i*=2){
        cout<<i<<'\t';
        SortSession->initBest(i);
        SortSession->sortArray();
        avgtime += SortSession->sortingTime();
        cout<<SortSession->sortingTime()*1000000<<'\t';
        SortSession->initWorst(i);
        SortSession->sortArray();
        avgtime += SortSession->sortingTime();
        cout<<SortSession->sortingTime()*1000000<<'\t';
        SortSession->init(i);
        SortSession->sortArray();
        avgtime += SortSession->sortingTime();
        cout<<SortSession->sortingTime()*1000000<<'\t';
        avgtime = (avgtime/3);
        cout<<avgtime*1000000<<" ns\t";
        if(i > startvar)
            cout<<avgtime*log10(prev_avgtime)/(prev_avgtime*log10(prev_avgtime))*avgtime*1000000<<" ns";
        prev_avgtime = avgtime;
        cout<<endl;
    }
}

void ComparisonDiagnostics(Sorting *SortSession, int startvar = 64, int endvar = 4096){
    cout<<"Size\tAsc\tDesc\tRandom\tAvg compares\n";
    int avgcount = 0;
    for(int i = startvar; i <= endvar; i*=2){
        cout<<i<<'\t';
        SortSession->initBest(i);
        SortSession->sortArray();
        avgcount += SortSession->comparisons();
        cout<<SortSession->comparisons()<<'\t';
        SortSession->initWorst(i);
        SortSession->sortArray();
        avgcount += SortSession->comparisons();
        cout<<SortSession->comparisons()<<'\t';
        SortSession->init(i);
        SortSession->sortArray();
        avgcount += SortSession->comparisons();
        cout<<SortSession->comparisons()<<'\t';
        cout<<(avgcount/3)<<endl;
    }
}

int main(){
    /*Sorting *SortSession = new BubbleSort;
    cout<<"Bubble sort\n";
    cout<<"Time\n";
    TimeDiagnostics(SortSession);
    cout<<"Comparisons\n";
    ComparisonDiagnostics(SortSession);
    delete SortSession;

    SortSession = new SelectionSort;
    cout<<"\nSelection sort\n";
    cout<<"Time\n";
    TimeDiagnostics(SortSession);
    cout<<"Comparisons\n";
    ComparisonDiagnostics(SortSession);
    delete SortSession;

    SortSession = new InsertionSort;
    cout<<"\nInsertion sort\n";
    cout<<"Time\n";
    TimeDiagnostics(SortSession);
    cout<<"Comparisons\n";
    ComparisonDiagnostics(SortSession);
    delete SortSession;*/

    Sorting *SortSession = new HeapSort;
    cout<<"\nHeap sort\n";
    SortSession->init(100);
    SortSession->printArray();
    SortSession->sortArray();
    SortSession->printArray();
    cout<<"Time\n";
    TimeDiagnostics(SortSession);
    cout<<"\nComparisons\n";
    ComparisonDiagnostics(SortSession);
    delete SortSession;

    /*SortSession = new QuickSort;
    cout<<"\nQuick sort\n";
    cout<<"Time\n";
    TimeDiagnostics(SortSession);
    cout<<"Comparisons\n";
    ComparisonDiagnostics(SortSession);
    delete SortSession;*/

}