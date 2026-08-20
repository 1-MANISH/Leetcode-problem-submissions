class Solution {
public:
    static bool comparator(pair<int,int>&a,pair<int,int>&b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mapping;
        for(auto &num:nums)mapping[num]++;
        vector<pair<int,int>>output;
        for(auto [element,count]:mapping){
            output.push_back({element,count});
        }
        sort(output.begin(),output.end(),comparator);
        vector<int>answer;
        for(int i = 0 ;i < k;i++){
            answer.push_back(output[i].first);
        }
        return answer;
    }
};