
class Solution {

public:
    int climbStairs(int n) {
        
        vector<int>dp(n+2,0);

        for(int start = n ; start >= 0;start--){
            
            int &ans = dp[start];
            // base case
            if(start>=n){
                ans = 1;
                continue;
            }

            // take 1 step
            int ans1 = dp[start+1];

            // take 2 step
            int ans2 = dp[start+2];

            ans = ans1+ans2;
        }
        return dp[0];
    }
};