#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &coins, int amount,
          unordered_map<int, int> &dp)
{
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return INT_MAX;
    }
    int mini = INT_MAX;
    for (int i : coins)
    {
        int ans;
        if (dp.count(amount - i))
        {
            ans = dp[amount - i];
        }
        else
        {
            ans = solve(coins, amount - i, dp);
            dp[amount - i] = ans;
            if (ans != INT_MAX)
            {
                mini = min(mini, 1 + ans);
            }
        }
    }
    return mini;
}

int coinChange(vector<int> &coins, int amount)
{
    int mini = INT_MAX;
    unordered_map<int, int> dp;
    mini = solve(coins, amount, dp);
    return (mini == INT_MAX) ? -1 : mini;
}

int main()
{

    vector<int> v = {1, 2, 5};
    cout << coinChange(v, 11);

    return 0;
}