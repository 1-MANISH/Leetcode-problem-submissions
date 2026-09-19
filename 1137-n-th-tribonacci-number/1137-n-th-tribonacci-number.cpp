const int N = 38;
int dp[N];

class Solution {

    int trib(int n){

        if(n==0)return 0;

        if(n<=2)return 1;

        if(dp[n]!=-1)return dp[n];

        return dp[n] =  trib(n-1)+trib(n-2)+trib(n-3);

    }
public:
    int tribonacci(int n) {

        memset(dp,-1,sizeof dp);

        return trib(n);
        
    }
};