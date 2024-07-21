#include<iostream>

using namespace std;

int main() {

    int n = 1;
    // cin >> n;
    int arr[11] = {5, 3, 1, 5, 1, 3, 4, 7, 4, 8, 8};
    // for(int i = 0; i < 11; i++) {
    //     cin >> a[i];
    // }
    // if(n == 1) {
    //     return arr[0];
    // }  
    for(int i = 0; i < n - 1; i++) {
        bool duplicate = false;
        if(arr[i] != -1) {
            for(int j = j + 1; j < n; j++) {
                if(arr[i] == arr[j]) {
                    arr[j] = -1;
                    cout << j << " " << arr[j] << endl;
                    duplicate = true;
                    break;
                }
            }
        }     
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }   
        cout << endl;
        if(!duplicate && arr[i] != -1) {
            break;
            cout << arr[i];
        }
    }

    return 0;
}