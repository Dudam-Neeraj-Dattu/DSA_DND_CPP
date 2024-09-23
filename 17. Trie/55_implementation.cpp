#include<bits/stdc++.h>

using namespace std;

class TrieNode {
    public:
        char ch;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) {
            this -> ch = ch;
            for(int i = 0; i < 26; i++) {
                this -> children[i] = NULL;
            }
            this -> isTerminal = false;
        }
};

class Trie {
    public:
        TrieNode* root;
    
    public:

        Trie() {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word) {
            if(word.length() == 0) {
                root -> isTerminal = true;
                return;
            }

            //assumption, word will be in CAPS

            int index = word[0] - 'A';
            TrieNode *child;

            if(root -> children[index] != NULL) {
                child = root -> children[index];
            }

            else {
                child = new TrieNode(word[0]);
                root -> children[index] = child;
            }

            insertUtil(child, word.substr(1));

        }

        void insertWord(string word) {
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode *root, string word) {
            if(word.length() == 0) {
                return root -> isTerminal;
            }

            int index = word[0] - 'A';
            TrieNode *child;

            if(root -> children[index] != NULL)  {
                child = root -> children[index];
            }

            else {
                return false;
            }

            return searchUtil(child, word.substr(1));
        }

        bool searchWord(string word) {
            return  searchUtil(root, word);
        }

        void removeUtil(TrieNode *root, string word) {
            if(word.length() == 0) {
                root -> isTerminal = false;
                return;
            }

            int index = word[0] - 'A';
            TrieNode *child;

            if(root -> children[index] != NULL)  {
                child = root -> children[index];
            }

            else {
                //word not found
                return;
            }

            removeUtil(child, word.substr(1));
        }

        void removeWord(string word) {
            removeUtil(root, word);
        }
};

int main() {

    Trie *t = new Trie();

    t -> insertWord("ABCD");
    t -> insertWord("ABC");
    
    cout << "present or not " << t -> searchWord("ABC") << endl;

    t -> removeWord("ABC");

    cout << "present or not " << t -> searchWord("ABC") << endl;
    return 0;
}