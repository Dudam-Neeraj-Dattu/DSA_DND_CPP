#include<iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int spaces = n - i;
        for(int j = 1; j <= spaces; j++) {
            cout << " ";
        }
        for(int j = spaces + 1; j <= n; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}