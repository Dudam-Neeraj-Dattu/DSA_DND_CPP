#include<iostream>

using namespace std;

int main() {

    int n;
    cin >> n;    
    for(int i = 1; i <= n; i++) {
        char c = 'A' + n - i;
        for(int j = 1; j <= i; j++) {
            cout << c++ << " ";
        }
        cout << endl;
    }

    return 0;
}