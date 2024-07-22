#include<iostream>

using namespace std;

int main() {
    
    int n = 5;
    int a[5] = {65, 25, 22, 10, 11};
    bool swapped = false;
    for(int i = 0; i < n - 1; i++) {                
        for(int j = 0; j < n - 1 - i; j++) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if(!swapped) {
            break;
        }
        for(int i : a) {
            cout << i << " ";
        }cout << endl;
    }
    for(int i : a) {
        cout << i << " ";
    }
    return 0;
}