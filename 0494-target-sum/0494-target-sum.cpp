const int N = 20+10;
const int S = 1e6+10;
const int X = 1e3+10;
 
int dp[N][S];
 
class Solution {

    int targetSumCount(int index,int currentSum,int &targetSum,int &n,vector<int>&arr){
    
        if(index>=n){
            return currentSum == targetSum;
        }
    
        if(dp[index][currentSum+X]!=-1){
            return dp[index][currentSum+X];
        }
    
        // take +
        int a1 = targetSumCount(index+1,currentSum+arr[index],targetSum,n,arr);
    
        // take -
        int a2 = targetSumCount(index+1,currentSum-arr[index],targetSum,n,arr);
    
        return dp[index][currentSum+X]=  a1+a2;
    }
 
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        memset(dp,-1,sizeof dp);
        return targetSumCount(0,0,target,n,nums);
    }
};