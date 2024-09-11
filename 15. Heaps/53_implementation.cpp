#include<bits/stdc++.h>

using namespace std;

class heap {
    public:
        int a[100];
        int size;
    
    public:
        heap() {
            a[0] = INT_MIN;
            size = 0;
        }

        void insert(int data) {

            //step1: insert at end
            size++;
            a[size] = data;
            int pos = size;
            //step2: make it to correct position
            while(pos > 1) {
                if(a[pos] > a[pos/2]) {
                    swap(a[pos/2], a[pos]);
                    pos = pos/2;
                }
                else {
                    break;
                }
            }        
        }

        void print() {
            for(int i = 1; i <= size; i++) {
                cout << a[i] << " ";
            }
        }
};



int main() {

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    return 0;
}