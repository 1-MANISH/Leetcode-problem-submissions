class Solution {
public:

    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>hashing;
        for(int i = 0 ; i < n ; i++){
            if(hashing.find(target-nums[i])!=hashing.end()){
                return {hashing[target-nums[i]],i};
            }else{
                hashing[nums[i]]=i;
            }
        }
        return {-1,-1};
    }
};