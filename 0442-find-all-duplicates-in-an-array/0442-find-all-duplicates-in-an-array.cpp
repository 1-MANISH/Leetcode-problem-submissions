class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>output;
        int n = nums.size() ,  current  = nums[0];
        for(int i = 1  ; i < n ; i++){
            if(nums[i]==current){
                output.push_back(current);
            }else{
                current=nums[i];
            }
        }
        return output;
    }
};