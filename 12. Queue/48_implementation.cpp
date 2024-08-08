#include<bits/stdc++.h>

using namespace std;

class Queue {

    public:

        int size;
        int *a;
        int front, rear;

    public:

        Queue(int size) {
            this -> size = size;
            this -> front = -1;
            this -> rear = 0;
            this -> a = new int[size];
        }

        void push(int data) {
            if(rear == size) {
                cout << "Queue overflow\n";
            }

            else {
                a[rear] = data;
                rear++;
                front = 0;
            }
        }

        void pop() {
            if(front == -1) {
                cout << "Queue is empty\n";
            }

            else {
                for(int i = 0; i < rear - 1; i++) {
                    a[i] = a[i + 1];
                }
                rear--;
                if(rear == 0) {front = -1;}
            }
        }

        int peek() {
            return (front == -1) ? -1 : a[front];
        }

        bool isEmpty() {
            return (front == -1);
        }
};

int main() {

    Queue q(5);
    
    q.push(4);

    cout << q.peek() << endl;

    q.push(1);

    q.push(2);

    q.push(3);

    q.push(5);

    q.push(6);

    q.pop();

    cout << q.peek() << endl;

    q.pop();

    cout << q.peek() << endl;








    return 0;
}