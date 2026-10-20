const int N = 1e4;
int dp[N];


class Solution {
    int solve(int index,vector<int>&nums){
        // base case
        if(index>=nums.size()-1){
            return 0;
        }

        if(dp[index]!=-1)return dp[index];

        // take all possible jumps
        int ans = INT_MAX/4;
        for(int step = 1 ; step <= nums[index];step++){
            int t_ans = 1+solve(index+step,nums);
            ans = min(ans,t_ans);
        }
        return dp[index] = ans;
    }
public:
    int jump(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return solve(0,nums);
    }
};