#include<iostream>

using namespace std;

int main() {
    
    // int n = 7;
    // int a[7] = {10, 1, 7, 4, 8, 2, 11};
    int n = 5;
    int a[5] = {65, 25, 22, 10, 11};
    for(int i = 1; i < n; i++) {                        
        int index = i, currelt = a[i];
        for(int j = i - 1; j >= 0; j--) {
            if(currelt < a[j]) {
                index = j;
            }
            else{
                break;
            }
        }        
        for(int j = i - 1; j >= index; j--) {
            a[j + 1] = a[j];
        }
        a[index] = currelt;
        cout << i << "->";
        for(int i : a) {
            cout << i << " ";
        }cout << endl;
    }
    for(int i : a) {
        cout << i << " ";
    }
    return 0;
}