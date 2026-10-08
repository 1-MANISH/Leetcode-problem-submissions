
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,1);
        vector<int>candidates(n+1,INT_MAX); // length  - best candidates
        candidates[0]=INT_MIN;
        for(int i = 0 ; i < n ; i++){
            auto it = lower_bound(candidates.begin(),candidates.end(),nums[i]);
            *it = nums[i]; // placing best candidates to correct length of subsequence
            dp[i] = it - candidates.begin() ; // elements less than nums[i] in [0....i-1]
        }
        return *max_element(dp.begin(),dp.end());
    }
};