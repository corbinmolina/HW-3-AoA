#include <iostream>
#include <algorithm>
#include "Sort.h"

using namespace std;

// Constructor: Allocates memory and copies the input list [cite: 10]
Sort::Sort(char *list, int num) {
    size = num;
    dataItems = new char[size];
    for (int i = 0; i < size; i++) {
        dataItems[i] = list[i];
    }
}

// Destructor: Deallocates memory [cite: 10]
Sort::~Sort() {
    delete[] dataItems;
}

// Selection Sort: Finds the minimum element and swaps it [cite: 7, 10]
void Sort::selectionSort() {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (dataItems[j] < dataItems[minIndex]) {
                minIndex = j;
            }
        }
        swap(dataItems[i], dataItems[minIndex]);
    }
}

// Insertion Sort: Builds the sorted list one item at a time [cite: 8, 10]
void Sort::insertionSort() {
    for (int i = 1; i < size; i++) {
        char key = dataItems[i];
        int j = i - 1;
        while (j >= 0 && dataItems[j] > key) {
            dataItems[j + 1] = dataItems[j];
            j--;
        }
        dataItems[j + 1] = key;
    }
}

// Public wrapper for Merge Sort [cite: 5, 10]
void Sort::MERGESORT() {
    mergeSort(dataItems, size);
}

void Sort::mergeSort(char *list, int n) {
    if (n < 2) return;
    int mid = n / 2;
    char *left = new char[mid];
    char *right = new char[n - mid];

    for (int i = 0; i < mid; i++) left[i] = list[i];
    for (int i = mid; i < n; i++) right[i - mid] = list[i];

    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(left, mid, right, n - mid, list);

    delete[] left;
    delete[] right;
}

void Sort::merge(char *A, int p, char *B, int q, char *C) {
    int i = 0, j = 0, k = 0;
    while (i < p && j < q) {
        if (A[i] <= B[j]) C[k++] = A[i++];
        else C[k++] = B[j++];
    }
    while (i < p) C[k++] = A[i++];
    while (j < q) C[k++] = B[j++];
}

// Public wrapper for Quick Sort [cite: 6, 10]
void Sort::QUICKSORT() {
    quickSort(dataItems, 0, size - 1);
}

void Sort::quickSort(char *list, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(list, left, right);
        quickSort(list, left, pivotIndex - 1);
        quickSort(list, pivotIndex + 1, right);
    }
}

int Sort::partition(char *list, int left, int right) {
    char pivot = list[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (list[j] <= pivot) {
            i++;
            swap(list[i], list[j]);
        }
    }
    swap(list[i + 1], list[right]);
    return i + 1;
}

// Utility to print the current state of the array [cite: 10]
void Sort::print() {
    for (int i = 0; i < size; i++) {
        cout << dataItems[i] << (i == size - 1 ? "" : " ");
    }
    cout << endl;
}
