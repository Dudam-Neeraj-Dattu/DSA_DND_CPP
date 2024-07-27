#include<iostream>

using namespace std;

int partition(int a[], int start, int end) {

    int pivot = start;
    for(int i = start + 1; i <= end; i++) {
        if(a[i] <= a[start]) {
            pivot++;
        }
    }
    swap(a[start], a[pivot]);

    int i = start, j = end;

    while(i < pivot && j > pivot) {
        if(a[i] <= a[pivot]) {
            i++;
        }
        else {
            swap(a[i], a[j]); 
            j--;           
        }
    }

    return pivot;

}

void quickSort(int a[], int start, int end) {
    if(start >= end) {
        return;
    }

    int p = partition(a, start, end);

    quickSort(a, start, p - 1);

    quickSort(a, p + 1, end);
}

int main() {

    int a[8] = {3, 4, 1, 2, 6, 8, 9, 0};

    quickSort(a, 0, 7);

    for(int i : a) {
        cout << i << " ";
    }

    return 0;
}