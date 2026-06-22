class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(0);
        for(int i = 0 ; i < n ;i++){
            while(nums[nums[i]]!=nums[i])swap(nums[nums[i]],nums[i]);
        }
        vector<int>output;
        for(int i  = 0 ; i < n ; i++){
            if(nums[i]!=i){
                output.push_back(nums[i]);
                output.push_back(i==0 ?n:i);
                break;
            }
        }
        nums.pop_back();
        return output;
    }
};