#include<bits/stdc++.h>

using namespace std;

int main() {

    stack<int> s;

    s.push(2);
    s.push(19);

    s.pop();

    cout << s.top();

    (s.empty()) ? cout << "empty" : cout << "not empty";
    
    return 0;
}