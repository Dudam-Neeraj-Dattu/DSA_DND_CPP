#include<bits/stdc++.h>

using namespace std;

class node {
    public:
        int data;
        node *left;
        node *right;

    public:
        node(int data) {
            this -> data = data;
            this -> left = left;
            this -> right = right;
        }
};

node* buildTree(node *root) {
    cout << "Enter the element\n";

    int data;
    cin >> data;

    root = new node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter the left child element for " << data << endl;
    
    root -> left = buildTree(root -> left);

    cout << "Enter the right child element for " << data << endl;

    root -> right = buildTree(root -> right);

    return root;
}

void traversal(node *root) {

    if(root == NULL) {
        // cout << " -1 ";
        return;
    }

    cout << root -> data << " ";

    traversal(root -> left);

    traversal(root -> right);
}

int main() {

    node *root = NULL;

    root = buildTree(root);

    // cout << root -> data;// << " " << root -> left -> data << " " << root -> right -> data;

    traversal(root);

    return 0;
}