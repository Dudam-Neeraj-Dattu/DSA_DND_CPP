#include<iostream>

using namespace std;

bool isPresent(int a[], int size, int key) {
    if(size == 0) {
        return false;
    }
    else if(a[size - 1] == key){
        return true;
    }
    else {
        return isPresent(a, size - 1, key);
    }
}

int main() {

    int a[5] = {3, 1, 4, 2, 6};
    int key = 4;

    bool found = isPresent(a, 5, key);

    if(found) {
        cout << "Present";
    }
    
    else {
        cout << "Absent";
    }

    return 0;
}