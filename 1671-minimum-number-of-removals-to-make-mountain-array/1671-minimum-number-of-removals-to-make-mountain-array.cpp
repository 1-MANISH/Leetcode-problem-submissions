#define v vector
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
         // LIS ending at i
        v<int>left(n,1);
        for(int i = 0 ; i < n ; i++){
            for(int j = i-1 ; j>=0 ; j--){
                if(nums[j] < nums[i]){
                    left[i] = max(left[i],1+left[j]);
                }
            }
        }

        // LDS starting at i
        v<int>right(n,1);
        for(int i = n-1 ; i>=0 ; i--){
            for(int j = i+1; j < n ; j++){
                if(nums[j]< nums[i]){
                    right[i] = max(right[i],1+right[j]);
                }
            }
        }

        // give every index chance to become peak element
        int ans= 0 ;
        for(int i = 0 ; i < n ; i++){
            if(left[i] > 1 and right[i] > 1) // need to drop
                ans = max(ans,left[i]+right[i]-1);
        }
        return  n - ans;
    }
};