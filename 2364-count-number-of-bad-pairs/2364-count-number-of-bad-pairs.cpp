class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,long long>m;
        long long  n = nums.size();
        for(int i = 0  ; i < n ; i++){
            m[nums[i]-i]++;
        }
        long long totalPairs = (1LL * n * ( n-1) / 2LL );
        long long notBadpairs = 0 ;
        for(auto &ptr:m){
            long long k = ptr.second;
            notBadpairs +=  (1LL * k * (k-1) / 2LL);
        }
        return totalPairs-notBadpairs;
    }
};