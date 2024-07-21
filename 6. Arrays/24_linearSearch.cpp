#include<iostream>

using namespace std;

int main() {

    int a[10] = {2,3,4,4,3,21,3,4,12};
    int key;
    cin >> key;
    bool found = false;
    for(int i : a) {
        if(i == key) {
            cout << "found";
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "not found";
    }
    return 0;
}