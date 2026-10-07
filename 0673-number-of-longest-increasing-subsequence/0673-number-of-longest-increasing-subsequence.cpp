#define v vector

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        v<int>dp(n,1); // FOR LIS
        v<int>cnt(n,0); // FOR LIS COUNT
        
        for(int i = 0 ; i < n ; i++){
            for(int j = i-1 ; j >= 0 ; j--){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }   

        for(int i = 0 ; i < n ; i++)
        {
            if(dp[i]==1){
                cnt[i]=1;
                continue;
            }
            for(int j = i-1 ; j >=0 ;j--){
                if(nums[j] < nums[i] and dp[j] == dp[i]-1 ){
                        cnt[i] = cnt[i]+cnt[j];
                } 
            }
        }   
        int lis_len = *max_element(dp.begin(),dp.end());
        int ans = 0 ;
        for(int i = 0 ; i< n ; i++){
            if(dp[i]==lis_len){
                ans = ans+cnt[i];
            }
        }

       return ans;
    }
};