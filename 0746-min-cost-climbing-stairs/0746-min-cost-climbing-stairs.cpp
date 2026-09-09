
const int N = 1000 + 10;

class Solution {

    int dp[N];

public:
    int minCost(int step, int n, vector<int>& cost) {

        if (step >= n)
            return 0;

        if (dp[step] != -1) {
            return dp[step];
        }
        int ans1 = cost[step + 1] + minCost(step + 1, n, cost);

        int ans2 = INT_MAX;
        if (step + 2 <= n) {
            ans2 = cost[step + 2] + minCost(step + 2, n, cost);
        }

        return dp[step] =  min(ans1, ans2);
    }
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        if (n <= 1) return 0;
        vector<int>newCost(n+2,0);
        for(int i = 1 ; i<=n ;i++){
            newCost[i]=cost[i-1];
        }
        
        for (int i = 0; i <= n + 1; i++) {
            dp[i] = -1;
        }
        
        return minCost(0, n + 1, newCost);
    }
};