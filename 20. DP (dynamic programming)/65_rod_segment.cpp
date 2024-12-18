//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    void solve(vector<int> &multiple, vector<int> &multiplier, int index, int sum, int cuts, int &ans, int n)
    {
        if (index == 3 || sum > n)
        {
            if(sum == n) {
                ans = max(ans, cuts);
            }            
            return;
        }
        for (int i = 0; i <= multiplier[index]; i++)
        {
            solve(multiple, multiplier, index + 1, sum + multiple[index] * i, i + cuts, ans, n);
        }
    }

public:
    // Function to find the maximum number of cuts.

    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // Your code here
        vector<int> multiple(3), multiplier(3);
        multiple[0] = x;
        multiple[1] = y;
        multiple[2] = z;
        sort(multiple.begin(), multiple.end());
        for (int i = 0; i < 3; i++)
        {
            multiplier[i] = n / multiple[i];
        }
        int ans = 0;
        solve(multiple, multiplier, 0, 0, 0, ans, n);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int n;
    cin >> n;

    // taking types of segments
    int x, y, z;
    cin >> x >> y >> z;
    Solution obj;
    // calling function maximizeTheCuts()
    cout << obj.maximizeTheCuts(n, x, y, z) << endl;

    return 0;
}
// } Driver Code Ends