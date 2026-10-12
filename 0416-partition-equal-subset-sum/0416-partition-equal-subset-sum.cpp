const int N = 200;
const int S = 20000;
int dp[N][S];

class Solution {

bool can(int index,int sum,int totalSum,vector<int>&nums){

    if(index==nums.size()){
        return totalSum-sum==sum;
    }
    if(dp[index][sum]!=-1)return dp[index][sum];
    // not take it
    bool ans1 = can(index+1,sum,totalSum,nums);

    // take it
    bool ans2 = can(index+1,sum+nums[index],totalSum,nums);

    return dp[index][sum] = ans1 or ans2;
}
public:
    bool canPartition(vector<int>& nums) {
        int totalSum  = 0 ;
        for(auto &x:nums)totalSum+=x;
        memset(dp,-1,sizeof dp);
        return can(0,0,totalSum,nums);
    }
};