const int N =3e1+10;
int dp[N];

class Solution {
public:
    int fibHelper(int n) {
        if(n==0 || n==1)return n;
        if(dp[n]!=-1)return dp[n];
        return dp[n] =  fibHelper(n-1)+fibHelper(n-2);
    }
    int fib(int n) {
        memset(dp,-1,sizeof dp);
        return fibHelper(n);
    }
};