class Solution
{
    public:
        vector<int> maxSlidingWindow(vector<int> &nums, int k)
        {
            int n = nums.size();
            vector<int>output;
            priority_queue<pair<int,int>> maxHeap;
            // first window
            for (int i = 0; i < k; i++) {
                maxHeap.push({nums[i],i});
            }
            output.push_back(maxHeap.top().first);
            // further windows
            for(int i = k ; i< n ; i++){
                if(maxHeap.top().second<=i-k){
                    while(!maxHeap.empty() && maxHeap.top().second<=i-k)maxHeap.pop();
                }
                maxHeap.push({nums[i],i});
                output.push_back(maxHeap.top().first);
            }
            return output;
        }
};