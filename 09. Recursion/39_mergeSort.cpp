#include<iostream>

using namespace std;

void merge(int a[], int start, int end) {

    int mid = (start + end) / 2;

    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];
    int k = start;
    for(int i = 0; i < len1; i++) {
        first[i] = a[k++];
    }
    // k = mid + 1;
    for(int i = 0; i < len2; i++) {
        second[i] = a[k++];
    }

    k = start;
    int i = 0, j = 0;
    while(i < len1 && j < len2) {
        if(first[i] < second[j]) {
            a[k++] = first[i++];
        }
        else {
            a[k++] = second[j++];
        }
    }

    while(i < len1) {
        a[k++] = first[i++];
    }

    while(j < len2) {
        a[k++] = second[j++];
    }

    delete []first;
    delete []second;

}   

void mergeSort(int a[], int start, int end) {
    if(start >= end) {
        return;
    }
    int mid = (start + end) / 2;

    mergeSort(a, start, mid);

    mergeSort(a, mid + 1, end);

    merge(a, start, end);  
}

int main() {

    int a[7] = {38, 27, 43, 3, 9, 82, 10};

    mergeSort(a, 0, 6);

    for(int i : a) {
        cout << i << " ";
    } 

    return 0;
}