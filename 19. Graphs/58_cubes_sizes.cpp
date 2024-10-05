#include<bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &size, int k, vector<int> &curr) {    
    curr[0]++;
    curr[1] += size[node];
    if(curr[0] == k) {
        return;
    }
    if(node == 1) {    
        curr[2] = min(curr[2], curr[1]);
        return;
    }    
    for(int i : adj[node]) {
        dfs(i, adj, size, k, curr);
        curr[1] -= size[i];
        curr[0]--;
    }   
}

int shortestHeight(int V, vector<int> adj[], vector<int> &size, int k) {
    vector<int> curr = {0, 0, INT_MAX};
    //curr[0] = current Count
    //curr[1] = current Height
    //curr[2] = shortest Height
    vector<int> path;
    dfs(0, adj, size, k, curr);
    return curr[2];
}

int main() {

    vector<int> adj[5];
    vector<int> size = {8, 15, 11, 10, 7};
    adj[0] = {2, 3};
    adj[1] = {0, 2};
    adj[2] = {1, 3, 4};
    adj[3] = {0, 1, 2};
    adj[4] = {1};
    int V = 5;
    int k = 4;
    cout << shortestHeight(V, adj, size, k);
    return 0;
}