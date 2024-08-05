#include<iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    // char c = 'A';
    for(int i = 'A'; i < 'A' + n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << char(i) << " ";
        }
        cout << endl;
    }

    return 0;
}