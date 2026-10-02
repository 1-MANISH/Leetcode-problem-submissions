
class Solution {
public:
    int tribonacci(int n) {

        vector<int>dp(n+1,0);

        for(int i = 0 ; i <= n ; i++){

            int &ans = dp[i];

            if(i==0){
                ans = 0 ;
                continue;
            }

            if(i<=2){
                ans = 1 ;
                continue;
            }

            ans =  dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};