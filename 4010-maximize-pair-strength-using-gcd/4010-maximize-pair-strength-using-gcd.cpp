class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
         long long ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long g = gcd(nums[i], nums[j]);
                long long strength = (1LL * nums[i] / g) * (nums[j] / g);
                ans = max(ans, strength);
            }
        }

        return ans;
    }
};