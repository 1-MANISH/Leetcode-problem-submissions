const int N = 45;
int dp[N];

class Solution {

    int solve(int start , int n){

        // base case
        if(start>=n)return 1;

        if(dp[start]!=-1)return dp[start];

        // take 1 step
        int ans1 = solve(start+1,n);

        // take 2 step
        int ans2 = solve(start+2,n);

        return dp[start] = ans1+ans2;
    }
public:
    int climbStairs(int n) {
        memset(dp,-1,sizeof dp);
        return solve(1,n);
    }
};