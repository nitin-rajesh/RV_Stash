#ifndef SORTFUNCTIONS
#define SORTFUNCTIONS


class InsertionSort: public Sorting{
    void sortMe();
};

class BubbleSort: public Sorting{
    void sortMe();
};

class SelectionSort: public Sorting{
    void sortMe();
};

class MergeSort: public Sorting{
    void merge(int, int, int);
    void mergesort(int, int);
    void sortMe();
};

class QuickSort: public Sorting{
    void sortMe();
    void quicksort(int, int);
    int partition(int, int);
};

#endif