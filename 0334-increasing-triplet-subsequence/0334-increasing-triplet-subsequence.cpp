#define v vector
#define ll long long
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // lets form dp array
        //dp[i] =  length of LIS ending at i (i included)
        int n = nums.size(); 
        v<int>dp(n,1);
        v<ll>candidates(n+1,LLONG_MAX);
        candidates[0]=LLONG_MIN;
        // candidates[i] = [i=0 to i=n] -> best suitable element at length i
        for(int i = 0 ; i < n ; i++){
            // lower bound >= x
            auto it = lower_bound(candidates.begin(),candidates.end(),nums[i]);
            *it = nums[i];
            dp[i] = it - candidates.begin();
        }
        int len_lis = *max_element(dp.begin(),dp.end());
        return len_lis >=3;
    }
};