#include<iostream>

using namespace std;

void stringReverse(string &s, int start, int n) {
    if(start >= n) {
        return;
    }
    else {
        swap(s[start], s[n - 1]);
        stringReverse(s, start + 1, n - 1);
    }
}

int main() {

    string s = "abcde";

    stringReverse(s, 0, s.length());

    cout << s;

    return 0;
}