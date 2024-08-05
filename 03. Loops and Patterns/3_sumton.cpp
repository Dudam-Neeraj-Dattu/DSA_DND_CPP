#include<iostream>

using namespace std;

int main() {

    int n, sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cout << i << " ";
        sum += i;
    }
    cout << endl << sum;

    return 0;
}