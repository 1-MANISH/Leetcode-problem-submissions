struct Data{
    int value,count;
};
struct CompareData{
    bool operator()(const Data&a,const Data&b){
        return a.count>b.count;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto &num:nums)freq[num]++;
        priority_queue<Data,vector<Data>,CompareData>minHeap;
        for(auto [value,count]:freq){
            minHeap.push({value,count});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }
        vector<int>answer;
        while(!minHeap.empty()){
            answer.push_back(minHeap.top().value);
            minHeap.pop();
        }
        return answer;
    }
};