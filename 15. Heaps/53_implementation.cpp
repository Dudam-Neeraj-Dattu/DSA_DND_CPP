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
            }cout << endl;
        }

        void deleteFromHeap() {
            if(size == 0) {
                cout << "empty";
                return;
            }

            a[1] = a[size];
            size--;

            int i = 1;
            while(i < size) {
                int leftIndex = 2 * i;
                int rightIndex = 2 * i + 1;
                if(leftIndex < size && a[i] < a[leftIndex]) {
                    swap(a[i], a[leftIndex]);
                    i = leftIndex;
                }
                else if(rightIndex < size && a[i] < a[rightIndex]) {
                    swap(a[i], a[rightIndex]);
                    i = rightIndex;
                }
                else {
                    break;
                }
            }
        }
};

void heapify(vector<int> &v, int size, int i) {
    int largest = i, left = 2 * i, right = 2 * i + 1;
    if(left <= size && v[left] > v[largest]) {
        largest = left;
    }
    if(right <= size && v[right] > v[largest]) {
        largest = right;
    }
    if(largest != i) {
        swap(v[largest], v[i]);
        heapify(v, size, largest);
    }
 
}

void heapSort(vector<int> &v, int size) {
    while(size > 1) {
        swap(v[1], v[size]);
        size--;
        heapify(v, size, 1);
    }
}



int main() {

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();
    h.deleteFromHeap();
    h.print();

    vector<int> v = {-1, 54, 53, 55, 52, 50};
    // for(int i = v.size() / 2; i > 0; i--) {
    //     heapify(v, v.size(), i);
    // }

    // for(int i : v) {
    //     cout << i << " ";
    // }

    // cout << endl;

    heapSort(v, v.size() - 1);

    for(int i : v) {
        cout << i << " ";
    }

    return 0;
}