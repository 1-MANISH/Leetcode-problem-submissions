const int N = 2500;
int dp[N][N+1];


class Solution {

    int solve(int index,int prevIndex,vector<int>&nums){

        // base cases
        if(index==nums.size())
            return 0;

        if(dp[index][prevIndex]!=-1) return dp[index][prevIndex];

        //not take 
        int ans1 = solve(index+1,prevIndex,nums);

        // take it - if possible to make increasing a < b only
        int ans2 = 0 ;
        if(prevIndex==nums.size() or nums[prevIndex] < nums[index])
            ans2 = 1 + solve(index+1,index,nums);

        return dp[index][prevIndex] = max(ans1,ans2);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return solve(0,nums.size(),nums);
    }
};