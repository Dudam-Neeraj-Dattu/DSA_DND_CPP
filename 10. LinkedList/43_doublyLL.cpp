#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;
    
    public:        
        Node(int data) {
            this -> data = data;
            this -> prev = NULL;
            this -> next = NULL;
        }
};

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
}

void insertAtTail(Node* &head, int data) {
    Node* temp = new Node(data);
    Node* tail = head;
    while(tail -> next) {
        tail = tail -> next;
    }
    tail -> next = temp;
    temp -> prev = tail;
}

void insertAtPosition(Node* &head, int position, int data) {
    Node* temp = new Node(data);
    Node* p = head;
    int index = 1;
    if(position == 1) {
        temp -> next = head;
        head -> prev = temp;
        head = temp;
        return;
    }
    while(index < position - 1) {
        p = p -> next;
        index++;
    }
    temp -> next = p -> next;
    if(temp -> next) {
        temp -> next -> prev = temp;
    }    
    p -> next = temp;
    temp -> prev = p;
}

void deletePosition(Node* &head, int posititon) {
    Node* p = head, *q = head;
    int index = 1;
    if(posititon == 1) {
        head = p -> next;
        p -> next = NULL;
        head -> prev = NULL;
        return;
    }
    while(index < posititon) {
        q = p;
        p = p -> next;
        index++;
    }
    q -> next = p -> next;
    if(q -> next) {
        q -> next -> prev = q;
    }       
    p -> prev = p -> next = NULL;
    delete p;

}

void printLL(Node* head) {
    while(head) {
        cout << head -> data << " ";
        head = head -> next;
    }
    cout << endl;
}

int main() {
    
    Node* head = new Node(10);    
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    printLL(head);
    insertAtTail(head, 50);
    printLL(head);
    insertAtPosition(head, 2, 35);
    insertAtPosition(head, 7, 70);
    insertAtPosition(head, 1, 70);
    printLL(head);
    deletePosition(head, 3);
    printLL(head);
    deletePosition(head, 7);
    printLL(head);
    deletePosition(head, 1);
    printLL(head);
    return 0;
}