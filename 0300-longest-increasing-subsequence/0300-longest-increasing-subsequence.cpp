
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);
        for(int i = 0 ; i < n ; i++){
            dp[i] = 1; // single element form LIS
            for(int j = i-1 ; j >= 0 ; j--){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};