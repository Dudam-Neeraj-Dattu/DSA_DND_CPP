#include<iostream>

using namespace std;

int main() {
    
    int n = 5;
    int a[5] = {65, 25, 22, 10, 11};
    for(int i = 0; i < n - 1; i++) {  
        int minIndex = i;              
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);        
    }
    for(int i : a) {
        cout << i << " ";
    }
    return 0;
}