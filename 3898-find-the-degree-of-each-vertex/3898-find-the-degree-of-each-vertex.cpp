class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<int>degrees;
        for(auto &row:matrix){
            int deg=0;
            for(auto c_ele:row) deg+=c_ele;
            degrees.push_back(deg);
        }
        return degrees;
    }
};