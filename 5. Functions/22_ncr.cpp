#include<iostream>

using namespace std;

int nCr(int n, int r) {
    int numerator = 1, denominator = 1;
    int min_of_denominator = min(n - r, r);
    for(int i = 1; i <= min_of_denominator; i++) {
        numerator *= n--;
    }
    for(int i = 1; i <= min_of_denominator; i++) {
        denominator *= i;
    }
    return numerator / denominator;
}

int main() {

    int n, r;
    cin >> n >> r;

    cout << nCr(n, r);

    return 0;
}