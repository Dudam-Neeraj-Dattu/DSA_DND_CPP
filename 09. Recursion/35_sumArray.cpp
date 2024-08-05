#include<iostream>

using namespace std;

int getSum(int a[], int size) {    
    if(size == 0) {
        return a[0];
    }
    else {
        int n = getSum(a, size - 1);        
        return a[size] + n;
    }
}

int main() {

    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << "the sum is --> " << getSum(a, 9);

    return 0;
}