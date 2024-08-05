#include<iostream>

using namespace std;

int binarySearch(int a[], int key, int n) {
    int start = 0, end = n - 1, mid;    

    while(start <= end) {
        mid = start + ((end - start) / 2);
        if (a[mid] == key) {
            return mid;
        }
        else if (a[mid] < key) {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int main() {

    int a[10] = {2, 4, 6, 8, 10};
    // cout << " hello world";
    int key = 5;
    // cin >> key;

    cout << binarySearch(a, key, 5);

    return 0;
}