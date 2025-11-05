#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, vector<int> wt, vector<int> profit, int W)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(profit[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << "Selected Items" << endl;

    int w = W;
    for (int i = n; i > 0 && w > 0; --i)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            cout << wt[i - 1] << " " << profit[i - 1] << endl;
            w -= wt[i - 1];
        }
    }

    return dp[n][W];
}

int main()
{
    int n, W;
    cin >> n >> W;

    vector<int> weight(n), profit(n);

    for (int i = 0; i < n; ++i)
        cin >> weight[i];
    for (int i = 0; i < n; ++i)
        cin >> profit[i];

    int maxProfit = knapsack(n, weight, profit, W);
    cout << maxProfit << endl;
    return 0;
}