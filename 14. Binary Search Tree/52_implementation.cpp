#include<bits/stdc++.h>

using namespace std;

class Node {

    public:
        int data;
        Node *left;
        Node *right;

    public:
        Node (int data) {
            this -> data = data;
            this -> right = NULL;
            this -> left = NULL;
        } 

};

void buildBST(Node *root, int val) {
    if(root -> data < val) {
        if(root -> right) {
            buildBST(root -> right, val);
        }
        else {
            Node *temp = new Node(val);
            root -> right = temp;
            return;
        }
        
    }

    else if(root -> data > val) {
        if(root -> left) {
            buildBST(root -> left, val);
        }
        else {
            Node *temp = new Node(val);
            root -> left = temp;
            return;
        }
    }
}

void preorder(Node *root) {
    if(root == NULL) {
        return;
    }

    cout << root -> data << " "; 
    preorder(root -> left);
    preorder(root -> right);
}

void levelOrder(Node *root) {
    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        if(q.front() -> left) {
            q.push(q.front() -> left);
        }

        if(q.front() -> right) {
            q.push(q.front() -> right);
        }
        cout << q.front() -> data << " ";
        q.pop();
    }
}

void inorder(Node *root) {
    if(root == NULL) {
        return;
    }
    
    inorder(root -> left);
    cout << root -> data << " "; 
    inorder(root -> right);
}

int main() {

    int list[8] = {10, 7, 15, 5, 9, 17, 16, 19};

    Node *root = new Node(list[0]);

    for (int i = 1; i < 8; i++) {
        buildBST(root, list[i]);
    }

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    levelOrder(root);
    return 0;
}