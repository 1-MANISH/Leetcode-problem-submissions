class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // cyclic sort - [1,n];
        int n = nums.size();
        vector<int>output;
        for(int i  = 0 ; i < n ; i++){
            while(nums[nums[i]-1]!=nums[i])swap(nums[nums[i]-1],nums[i]);
        }

        for(int i  =  0 ; i < n ; i++){
            if(nums[i]!=i+1)output.push_back(i+1);
        }
        return output;
    }
};