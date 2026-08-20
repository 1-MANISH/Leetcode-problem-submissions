struct Data{
    int value,count;
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(auto &num:nums)freq[num]++;
        vector<Data>output;
        for(auto [value,count]:freq)output.push_back({value,count});
        priority_queue<Data,vector<Data>,decltype([](const Data &a,const Data &b){
            return a.count>b.count;
        })>minHeap;
        for(auto &data:output){
            minHeap.push(data);
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