#include <bits/stdc++.h>

using namespace std;

bool safe(int i, int j, vector<vector<int>> &v, vector<vector<bool>> &visited)
{
    return (i >= 0 && i < 3 && v[i][j] == 0 && visited[i][j] == false);
}
int solve(vector<vector<int>> &v, int i, int j, vector<vector<int>> &directions, vector<vector<bool>> &visited, vector<vector<int>> &dp)
{
    if (j == v[0].size() - 1)
    {
        return 0;
    }
    visited[i][j] = true;
    int mini = INT_MAX;
    if (dp[i][j] != -1)
    {
        visited[i][j] = false;
        return dp[i][j];
    }
    for (auto d : directions)
    {
        int jumps = 0;
        if (safe(i + d[0], j + d[1], v, visited))
        {
            if (d[0] != 0)
            {
                jumps = 1 + solve(v, i + d[0], j + d[1], directions, visited, dp);
            }
            else
            {
                jumps = solve(v, i + d[0], j + d[1], directions, visited, dp);
            }
            mini = min(mini, jumps);
        }
    }
    visited[i][j] = false;
    dp[i][j] = (mini == INT_MAX) ? INT_MAX - 1 : mini;
    return dp[i][j];
}

int minSideJumps(vector<int> &obstacles)
{
    vector<vector<int>> v(3, vector<int>(obstacles.size(), 0));
    for (int i = 0; i < obstacles.size(); i++)
    {
        if (obstacles[i] > 0)
        {
            v[obstacles[i] - 1][i] = 1;
        }
    }
    vector<vector<int>> directions = {{0, 1}, {-1, 0}, {-2, 0}, {1, 0}, {2, 0}};
    vector<vector<bool>> visited(3, vector<bool>(obstacles.size(), false));
    vector<vector<int>> dp(3, vector<int>(obstacles.size(), -1));
    return solve(v, 1, 0, directions, visited, dp);
}

int main()
{
    vector<int> obstacles = {0, 0, 3, 1, 0, 1, 0, 2, 3, 1, 0};
    cout << minSideJumps(obstacles);
    return 0;
}