class Solution {
public:
    int findMin(vector<int>& nums) {
        int start  = 0;
        int end = nums.size()-1;
        
        while(start <= end)
        {
            int mid = start+(end-start)/2;
            
            if(nums[mid] >= nums[0])
            {
                start = mid+1;
            }
            else
            {
                if(nums[mid]<nums[mid-1]) return nums[mid];
                end = mid;
            }
        }
        
        return nums[0];
    }
};