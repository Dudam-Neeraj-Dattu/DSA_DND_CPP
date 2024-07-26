#include<iostream>

using namespace std;

bool binarySearch(int a[], int start, int end, int key) {
    if(start > end) {
        return false;
    }
    int mid = (start + end) / 2;
    if(a[mid] == key) {
        return true;
    }
    else if(a[mid] < key) {
        return binarySearch(a, mid + 1, end, key);
    }
    else {
        return binarySearch(a, start, mid - 1, key);
    }
}

int main() {

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 11;

    cout << "present or not --> " << binarySearch(a, 0, 9, key);

    return 0;
}