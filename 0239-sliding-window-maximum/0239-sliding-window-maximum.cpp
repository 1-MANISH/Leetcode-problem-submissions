class Solution {
private:
    void addElementToDeque(deque<pair<int, int>>&dq, int& element,int &index) {
        // removing unneccery
        while(!dq.empty() && dq.back().first <= element)dq.pop_back();
        while(!dq.empty() && dq.front().first <= element)dq.pop_front();
        // adding - making decreasing queue -{back_max,front_min}
        if(dq.empty()) dq.push_back({element, index});
        else if(dq.back().first<element)dq.push_back({element,index});
        else dq.push_front({element,index});
    }

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        deque<pair<int, int>> dq; // back maximum and front minimum
        for (int i = 0; i < k; i++) {
           addElementToDeque(dq,nums[i],i);
        }
        output.push_back(dq.back().first);
        for (int i = k; i < nums.size(); i++) {
            // remove index<i-k+1 
            while (!dq.empty() && dq.front().second < i - k + 1 )dq.pop_front();
            while (!dq.empty() &&dq.back().second < i - k + 1 )dq.pop_back();
            // add current
            addElementToDeque(dq,nums[i],i);
            output.push_back(dq.back().first);
        }
        return output;
    }
};