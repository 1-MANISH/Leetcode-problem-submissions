

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
            // check started transaction done or not -  as also reach to max transaction
            return tranType==NONE ? 0 : INT_MIN;
        }


        if(dp[index][tranType][event]!=LONG_MIN){ 
            return dp[index][tranType][event];
        }

        long long  ans1 ,ans2,ans3;
        ans1=ans2=ans3=INT_MIN;

        // skip this day -  not starting any tranx

        ans1 = solve(index+1,tranType,event,k,prices);

        // dp the possible tranxation


        // nop transaction currently running
        if( tranType == NONE){
            // we can start normal
            ans2 = -prices[index] + solve(index+1,NORMAL_TRX,event+1,k,prices);
            // we can start short sell
            ans3 = +prices[index] + solve(index+1,SHORT_SELL,event+1,k,prices);
        }
        else if (tranType == NORMAL_TRX){ // normal transaction started need to complete
            // complete normal transaction
            ans2 = +prices[index] + solve(index+1,NONE,event+1,k,prices);
        }
        else{ // shrot selling running -  need to complete
            // complete short sell - buy noe
            ans3 = -prices[index] + solve(index+1,NONE,event+1,k,prices);
        }
        // return max profit
        return dp[index][tranType][event]= max(ans1,max(ans2,ans3));

    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        // default value of dp should never be answer
        // memset(dp,-1,sizeof dp);
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < 3 ; j ++){
                for(int p  = 0 ; p < N ; p++){
                    dp[i][j][p]=LONG_MIN;
                }
            }
        }
        return solve(0,NONE,0,k,prices);
    }
};