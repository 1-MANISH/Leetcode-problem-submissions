#define ll long long
const int N = 13;
const int S = 1e4;

ll dp[N][S];

class Solution {
    ll minCoinRequired(int index,int currentCoinSum,int &x,int n,vector<int>&coins){
    

        if(currentCoinSum>x)return INT_MAX-1;

        if(currentCoinSum==x)return 0;

        if(dp[index][currentCoinSum]!=-1)
            return dp[index][currentCoinSum];

        ll ans = INT_MAX;

        for(int i = index ; i < n ; i++){
            if(0LL+currentCoinSum+coins[i]<=x){
                // +1 as we took this coin
                ans = min(ans , 1+minCoinRequired(i,currentCoinSum+coins[i],x,n,coins));
            }
        }

        return dp[index][currentCoinSum] =  ans;

    }


public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof dp);
        ll  ans = minCoinRequired(0,0,amount,coins.size(),coins);
        return (ans==INT_MAX ? -1 :ans );
    }
};