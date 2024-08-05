#include<iostream>

using namespace std;

int counting(int n) {

    if(n == 1) {
        return 1;
    }
    else {
        int smallerProblem = counting(n - 1);
        int biggerProblem = n + smallerProblem;
        return biggerProblem;
    
    }
}

int main() {

    int n;
    cin >> n;

    cout << counting(n);

    return 0;
}