

class Solution {

public:

    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();

        if (n <= 1) return 0;

        vector<int>newCost(n+2,0);

        for(int i = 1 ; i<=n ;i++){
            newCost[i]=cost[i-1];
        }

        vector<int> dp(n+2,INT_MAX);


        for(int step  = n+1 ; step >=0 ; step--){

            int &ans = dp[step];

            if (step >= n){
                ans = 0;
                continue;
            }

   
            int ans1 = newCost[step + 1] + dp[step + 1];

            int ans2 = INT_MAX;
            if (step + 2 <= n+1) {
                ans2 = newCost[step + 2] + dp[step + 2];
            }
            ans =  min(ans1, ans2);
        }

        return dp[0];
    }
};