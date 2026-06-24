class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() , xorSum = 0;
        for(int i = 0 ; i<=n ; i++)xorSum^=i;
        for(int &ele:nums)xorSum^=ele;
        return xorSum;
    }
};