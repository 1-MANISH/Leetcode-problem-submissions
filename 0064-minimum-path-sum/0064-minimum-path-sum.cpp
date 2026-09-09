#define ll long long
const int N = 200;
const int M = 200;
class Solution {

    int dp[N + 1][M+1];

public:
    ll f(int i, int j, int n, int m, vector<vector<int>>& cost) {

        // not possible as - index not valid
        if (i >= n or j >= m)
            return INT_MAX;

        // reached at bottom right end - a[n-1][m-1];
        if (i == n - 1 && j == m - 1)
            return cost[i][j];

        // answer already exist
        if (dp[i][j] != -1)
            return dp[i][j];

        // right + down

        ll ans1 = cost[i][j] + f(i, j + 1, n, m, cost) ;
        ll ans2 = cost[i][j] + f(i + 1, j, n, m, cost) ;

        return dp[i][j] = 1LL*min(ans1,ans2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                dp[i][j] = -1;
            }
        }

        return f(0, 0, n, m, grid);
    }
};