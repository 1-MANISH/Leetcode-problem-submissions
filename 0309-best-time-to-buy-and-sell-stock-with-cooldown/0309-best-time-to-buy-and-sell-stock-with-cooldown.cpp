const int BUY = 0 ;
const int SELL = 1;

const int N  = 5e3;
int dp[N][2];

class Solution {

    int solve(vector<int>&prices,int index,int transactionType){

        if(index>=prices.size()){
            return 0;
        }

        if(dp[index][transactionType]!=-1) return dp[index][transactionType];
        // skip this day
        int ans1 =  solve(prices,index+1,transactionType);

        // do all posible operations/transactions
        int ans2 = 0 ;

        if(transactionType == BUY){
            ans2 = -prices[index]+solve(prices,index+1,SELL);
        }else{
            ans2 = +prices[index]+solve(prices,index+2,BUY);
        }

        return dp[index][transactionType] = max(ans1,ans2);

    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return solve(prices,0,BUY);
    }
};