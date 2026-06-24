class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0 , maxSum = INT_MIN , n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(currentSum+nums[i]<=0){
                maxSum=max(maxSum,nums[i]);
                currentSum=0;
            }else{
                currentSum+=nums[i];
                maxSum=max(maxSum,currentSum);
            }
        }
        return maxSum;
    }
};