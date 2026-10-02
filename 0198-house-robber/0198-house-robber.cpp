/*
    RECURSIVE :
        index = 0 to n
    TABULATION :
        index  =  n to 0
*/

class Solution {

public:
    int rob(vector<int>& nums) {

        int n  =  nums.size() ;

        vector<int>dp(n+2);

        for(int index = n ; index >= 0; index--){

            int &ans = dp[index];

            // base case
            if(index>=n){
                ans =  0;
                continue;
            }

            // not take it
            int ans1 = dp[index+1];

            // take it
            int ans2 = nums[index] + dp[index+2];

            ans =  max(ans1,ans2);

        }

        return dp[0];
    }
};