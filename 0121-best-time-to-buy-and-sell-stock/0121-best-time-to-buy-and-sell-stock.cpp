class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mx = prices[prices.size()-1];

        for(int i =prices.size()-2 ; i>=0  ; i--){
            ans = max(ans,mx-prices[i]);
            mx = max(mx,prices[i]);
        }
        
        return ans;
    }
};