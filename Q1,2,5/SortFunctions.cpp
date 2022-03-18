#include<iostream>
#include<vector>
#include"AllSorts.h"
#include"SortFunctions.h"
using std::swap;
using std::vector;

void InsertionSort::sortMe(){
    int i, key, j;
    int n = array.size();
    for (i = 1; i < n; i++)
    {
        key = array[i];
        j = i - 1;

        /* Move elements of array[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while ((j >= 0 && array[j] > key) & ++iterationCount)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void BubbleSort::sortMe(){
    for(int i = 0; i < array.size(); i++){
        for(int j = 0; j < array.size() - i - 1; j++){
            iterationCount++;
            if(array[j] > array[j+1]){
                swap(array[j],array[j+1]);
            }
        }
    }
}

void SelectionSort::sortMe(){
    int i, j, min_idx; 
    int n = array.size() - 1;
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
        iterationCount++;
        if (array[j] < array[min_idx]) 
            min_idx = j; 

        // Swap the found minimum element with the first element 
        swap(array[min_idx], array[i]); 
    } 
}

void MergeSort::merge(int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];
 
    // Merge the temp arrays back into array[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
        iterationCount++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}
void MergeSort::mergesort(int l, int r){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergesort(l,m);
    mergesort(m+1,r);
    merge(l,m,r);
}
void MergeSort::sortMe(){
    mergesort(0,array.size());
}


int QuickSort::partition (int low, int high)
{
    int pivot = array[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (array[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}

void QuickSort::quicksort(int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, array[p] is now
        at right place */
        int pi = partition(low, high);
        iterationCount += high - low - 1;
        // Separately sort elements before
        // partition and after partition
        quicksort(low, pi - 1);
        quicksort(pi + 1, high);
    }
}

void QuickSort::sortMe(){
    quicksort(0, array.size() - 1);
}


void HeapSort::heapify(int n, int i){
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2
  
    // If left child is larger than root
    iterationCount++;
    if (l < n && array[l] > array[largest])
        largest = l;
    
    // If right child is larger than largest so far
    iterationCount++;
    if (r < n && array[r] > array[largest])
        largest = r;
  
    // If largest is not root
    if (largest != i) {
        swap(array[i], array[largest]);
  
        // Recursively heapify the affected sub-tree
        heapify(n, largest);
    }
}
  

void HeapSort::heapsort()
{
    // Build heap (rearrange array)
    for (int i = array.size() / 2 - 1; i >= 0; i--)
        heapify(array.size(),i);
 
    // One by one extract an element from heap
    for (int i = array.size() - 1; i > 0; i--) {
        // Move current root to end
        swap(array[0], array[i]);
 
        // call max heapify on the reduced heap
        heapify(i,0);
    }
}

void HeapSort::sortMe(){
    heapsort();
}