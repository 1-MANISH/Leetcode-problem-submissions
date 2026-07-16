class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i , j ,flag = 0;
        i = n-2 , j = n-1;
        while(i>=0){
            if(nums[i]>=nums[j]){
                i--,j--;
            }else{
                int k = j;
                j++;
                while(j<n && nums[i]<nums[j])j++;
                if(j==n && nums[i]>nums[j-1])k=i+1;
                else k = j-1;
                swap(nums[i],nums[k]);
                j = n-1;
                i++;
                while(i<j)swap(nums[i++],nums[j--]);
                flag=1;
                break;
            }
        }
        if(flag==0){
            i=0,j=n-1;
            while(i<j)swap(nums[i++],nums[j--]);
        }
    }
};