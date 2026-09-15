// at most k transactions -  2*k events
// BUY SELL BUY SELL BUY SELL BUY SELL
// 0   1     2   3   4    5    6   7    ...2*k times

// BUY-even
// SELL-odd

const int BUY = 0;
const int SELL = 1;
const int N = 1e3;
const int K = 1e2;

int dp[N][2*K];// as number of transactions  = 2*k = 2*K = 2K


class Solution {

    int solve(vector<int>& prices,int index,int event,int &k){

        if(index==prices.size() or event==2*k){
            return 0;
        }
        if(dp[index][event]!=-1) return dp[index][event];
        // skip this day
        int ans1  =  solve(prices,index+1,event,k);

        int ans2 = 0 ;

        int transactionType = event & 1 ? SELL : BUY;

        if(transactionType == BUY){
            ans2 = -prices[index] + solve(prices,index+1,event+1,k);
        }else{
            ans2 = +prices[index] + solve(prices,index+1,event+1,k);
        }

        return dp[index][event]= max(ans1,ans2);
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return solve(prices,0,0,k);
    }
};