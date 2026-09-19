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
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>n1(n-1),n2(n-1);
        for(int i = 0 ; i < n-1  ; i++)
            n1[i]=nums[i];
        for(int i = 1 ; i < n  ; i++)
            n2[i-1]=nums[i];    
        memset(dp,-1,sizeof dp);
        int case1 = solve(0,n1);
        memset(dp,-1,sizeof dp);
        int case2  = solve(0,n2);

        return max(case1,case2);
    }
};