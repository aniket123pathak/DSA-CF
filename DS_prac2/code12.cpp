#include <bits/stdc++.h>
using namespace std;
int OBST(vector<int> &f, int n)
{
    vector<vector<int>> dp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        dp[i][i] = f[i];
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += f[k];
            for (int r = i; r <= j; r++)
            {
                int left = (r > i) ? dp[i][r - 1] : 0;
                int right = (r < j) ? dp[r + 1][j] : 0;
                dp[i][j] = min(dp[i][j], left + right + sum);
            }
        }
    }
    return dp[0][n - 1];
}
int main()
{
    int n;
    cin >> n;
    vector<int> f(n);
    for (int i = 0; i < n; i++)
        cin >> f[i];
    cout << "Optimal Cost: " << OBST(f, n);
}