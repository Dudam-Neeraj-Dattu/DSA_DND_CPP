#include<bits/stdc++.h>

using namespace std;

class Stack {
    
    public:
        int size;
        int top;
        int *arr;

    public:
        Stack(int size) {
            this -> size = size;
            top = -1;
            arr = new int[size];
        }

        void push(int element) {
            if(top < size - 1) {
                top++;
                arr[top] = element;
            }
            else {
                cout << "Stack Overflow\n"; 
            }
        }

        void pop() {
            if(top >= 0) {
                top--;
            }
            else {
                cout << "Stack Underflow\n";
            }
        }

        int peek() {
            if(top >= 0) {
                return arr[top];
            }
            else {
                cout << "Stack is Empty\n";
                return -1;
            }
        }

        bool isEmpty() {
            return (top == -1);
        }        

        ~Stack() {
            delete []arr;
        }

};

int main() {

    Stack st(3);
    cout << st.isEmpty() << endl;
    st.push(2);
    st.push(3);
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.push(4);
    st.push(5);
    cout << st.isEmpty();
    st.push(6);


    return 0;
}