#include<iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    int a[n] = {0};
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i += 2) {
        if(i + 1 != n) {
            swap(a[i], a[i + 1]);
        }        
    }
    for(int i : a) {
        cout << i << " ";
    }
    return 0;
}