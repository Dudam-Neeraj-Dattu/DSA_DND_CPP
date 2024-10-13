#include <bits/stdc++.h>

using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    vector<int> distance(V, INT_MAX);
    distance[S] = 0;
    set<pair<int, int>> s;
    s.insert(make_pair(0, S));
    while (!s.empty())
    {
        auto top = *s.begin();
        int nodeDistance = top.first;
        int node = top.second;
        s.erase(s.begin());
        for (vector<int> v : adj[top.second])
        {
            if (top.first + v[1] < distance[v[0]])
            {

                auto f = s.find(make_pair(distance[v[0]], v[0]));

                if (f != s.end())
                {
                    s.erase(f);
                }

                distance[v[0]] = top.first + v[1];
                s.insert(make_pair(distance[v[0]], v[0]));
            }
        }
    }
    return distance;
}

int main()
{
    vector<vector<int>> adj[4];
    adj[0].push_back({1, 9});
    adj[0].push_back({2, 1});
    adj[0].push_back({3, 1});
    adj[1].push_back({0, 9});
    adj[1].push_back({3, 3});
    adj[2].push_back({0, 1});
    adj[2].push_back({3, 2});
    adj[3].push_back({0, 1});
    adj[3].push_back({1, 3});
    adj[3].push_back({2, 2});
    vector<int> distance = dijkstra(4, adj, 0);
    for (int i : distance)
    {
        cout << i << " ";
    }
    return 0;
}