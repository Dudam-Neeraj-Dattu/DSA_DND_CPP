#include <bits/stdc++.h>
using namespace std;
void solve(int position, int &p, int n, int sum, vector<int> &cost)
{
    // Base case: if we are at or beyond the last step, update the minimum cost
    if (position >= n - 1)
    {
        p = min(p, sum);
        return;
    }

    // If stepping 1 step ahead is within bounds
    if (position + 1 < n)
    {
        solve(position + 1, p, n, sum + cost[position + 1], cost);
    }

    // If stepping 2 steps ahead is within bounds
    if (position + 2 < n)
    {
        solve(position + 2, p, n, sum + cost[position + 2], cost);
    }
}

int minCostClimbingStairs(vector<int> &cost)
{
    int p = INT_MAX; // Set initial minimum cost to a large value
    int n = cost.size();

    // You can start from step 0 or step 1
    solve(0, p, n, cost[0], cost); // Start from step 0
    solve(1, p, n, cost[1], cost); // Start from step 1

    return p; // Return the minimum cost to reach the top
}
int main()
{
    vector<int> cost = {10, 15, 20};
    cout << minCostClimbingStairs(cost);
    return 0;
}