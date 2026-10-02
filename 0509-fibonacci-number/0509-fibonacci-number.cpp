
class Solution {
public:

    int fib(int n) {
        vector<int>dp(n+1,0);
        for(int i = 0 ; i <= n ; i++){
            int &ans = dp[i];
            if(i==0){
                ans=0;
                continue;
            }
            if(i==1){
                ans=1;
                continue;
            }
            int ans1 = dp[i-1];
            int ans2 = dp[i-2];

            ans = (ans1+ans2);
        }
        return dp[n];
    }
};