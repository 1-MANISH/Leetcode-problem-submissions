class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size() , i = 0 , j  = nums.size()-1;
        while(i<j){
            while(i<n && nums[i]==0)i++;
            while(j>=0 && nums[j]!=0)j--;
            if(i<j){
                swap(nums[i++],nums[j--]);
            }
        }
        i = 0 , j = n-1;
        while(i<j){
            while(i<n && nums[i]!=2)i++;
            while(j>=0 && nums[j]==2)j--;
            if(i<j){
                swap(nums[i++],nums[j--]);
            }
        }

    }
};