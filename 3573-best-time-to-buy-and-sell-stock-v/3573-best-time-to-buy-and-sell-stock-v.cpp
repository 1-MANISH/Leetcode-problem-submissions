

const int NONE = 0;
const int NORMAL_TRX = 1;
const int SHORT_SELL = 2;
const int N = 1e3;
const int K = 1e3;
long long dp[N][3][K];

class Solution {

    long long solve(int index,int tranType,int event,int &k,vector<int>&prices){
        // base case

        if(index==prices.size() or event==2*k){
            return tranType==NONE ? 0 : INT_MIN;
        }


        if(dp[index][tranType][event]!=-1){
            return dp[index][tranType][event];
        }

        long long  ans1 ,ans2,ans3;
        ans1=ans2=ans3=LONG_MIN;

        // skip this day

        ans1 = solve(index+1,tranType,event,k,prices);

        // dp the possible tranxation

        if( tranType == NONE){
            // we can start normal
            ans2 = -prices[index] + solve(index+1,NORMAL_TRX,event+1,k,prices);
            // we can start short sell
            ans3 = +prices[index] + solve(index+1,SHORT_SELL,event+1,k,prices);
        }
        else if (tranType == NORMAL_TRX){
            // complete normal transaction
            ans2 = +prices[index] + solve(index+1,NONE,event+1,k,prices);
        }
        else{
            // complete short sell - buy noe
            ans3 = -prices[index] + solve(index+1,NONE,event+1,k,prices);
        }

        return dp[index][tranType][event]= max(ans1,max(ans2,ans3));

    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        memset(dp,-1,sizeof dp);
        return solve(0,NONE,0,k,prices);
    }
};