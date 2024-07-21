#include<iostream>

using namespace std;

int main() {

    int size;
    cin >> size;
    int a[size] = {0};
    for(int i = 0; i < size; i++) {
        cin >> a[i];
    }
    int j = size - 1;
    for(int i = 0; i < size/2; i++) {
        int temp = a[j];
        a[j--] = a[i];
        a[i] = temp; 
    }
    for(int i : a) {
        cout << i << " ";
    }
    return 0;
}