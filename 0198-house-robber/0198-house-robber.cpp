const int N = 1e2;
int dp[N];

class Solution {

    int solve(int index,vector<int>&nums){

        // base case
        if(index>=nums.size()){
            return 0;
        }

        if(dp[index]!=-1){
            return dp[index];
        }

        // lets not choose this house - try to get from next home
        int ans1 = solve(index+1,nums);

        // lets choose this ith index house- mean rob this one
        int ans2 = nums[index]+solve(index+2,nums);

        return dp[index] =  max(ans1,ans2);
    }
public:
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return solve(0,nums);
    }
};