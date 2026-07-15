class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>output;
        priority_queue<pair<int,int>>maxHeap;
        for(int i = 0 ; i< k ; i++){
            maxHeap.push({nums[i],i});
        }
        output.push_back(maxHeap.top().first);
        for(int i = k ; i< nums.size() ; i++){
            // remove index<i-k+1;
            while(!maxHeap.empty() && maxHeap.top().second<i-k+1)maxHeap.pop();
            maxHeap.push({nums[i],i});
            output.push_back(maxHeap.top().first);
        }
        return output;
    }
};