#include<bits/stdc++.h>

using namespace std;
template <typename T>

class graph {
    public:
        unordered_map<T, list<T>> adj;
        
    public:
        void addEdge(T u, T v, bool direction) {
            //direction = 0 -> undirected
            //direction = 1 -> directed graph

            //create an edge from u to v

            adj[u].push_back(v);
            if(direction == 0) {
                adj[v].push_back(u);
            }
        }

        void printAdjList() {
            for(auto i : adj) {
                cout << i.first << " -> ";
                for(auto j : i.second) {
                    cout << j << ", ";
                }
                cout << endl;
            }
        }
};

int main() {

    int n, m;
    cin >> n >> m;
    graph<int> g;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        //undirected graph
        g.addEdge(u, v, 0);
    }

    //printing graph
    g.printAdjList();
    

    return 0;
}