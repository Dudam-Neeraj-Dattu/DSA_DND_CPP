#include<bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h> 

void insertAtitsPosition(stack<int> &stack, int x) {

	if(stack.empty() || stack.top() < x) {
		stack.push(x);
		return;
	}

	int y = stack.top();

	stack.pop();

	insertAtitsPosition(stack, x);

	stack.push(y);

}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()) {
		return;
	}

	int x = stack.top();

	stack.pop();

	sortStack(stack);

	insertAtitsPosition(stack, x);
}

int main() {

    stack<int> s;

    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(7);
    s.push(3);

    sortStack(s);

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}