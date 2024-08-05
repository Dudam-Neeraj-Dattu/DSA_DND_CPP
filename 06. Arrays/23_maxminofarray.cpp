#include<iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    int a[n] = {0};
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mini = a[0], maxi = a[0];
    for(int i = 1; i < n; i++) {
        mini = min(mini, a[0]);
        maxi = max(maxi, a[i]);
    }
    cout << mini << " " << maxi;
    return 0;
}