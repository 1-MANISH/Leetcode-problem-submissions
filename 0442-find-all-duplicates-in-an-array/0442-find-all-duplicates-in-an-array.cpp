class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size() ;
        nums.push_back(0);
        vector<int>output;
        for(int i = 0  ; i <= n ; i++){
            while(nums[nums[i]]!=nums[i])swap(nums[nums[i]],nums[i]);
        }
        for(int i = 1 ; i <=n ; i++){
            if(nums[i]!=i)output.push_back(nums[i]);
        }
        nums.pop_back();
        return output;
    }
};