class MyAggregateQueue {
public:
    stack<pair<int, int>> inStack, outStack;
    MyAggregateQueue() {}

    // O(1)
    void push(int x) {
        if (inStack.empty())
            inStack.push({x, x});
        else
            inStack.push({x, max(x, inStack.top().second)});
    }

    // Amortized - O(1)
    void pop() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                if (outStack.empty()) {
                    outStack.push({inStack.top().first,inStack.top().first});
                } else {
                    outStack.push({inStack.top().first,max(inStack.top().first, outStack.top().second)});
                }
                inStack.pop();
            }
        }
        outStack.pop();
    }

    int getMax() {
        if (inStack.empty())
            return outStack.top().second;
        if (outStack.empty())
            return inStack.top().second;
        return max(inStack.top().second, outStack.top().second);
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        MyAggregateQueue sQueue;
        for (int i = 0; i < k; i++) {
            sQueue.push(nums[i]);
        }
        output.push_back(sQueue.getMax());
        for (int i = k; i < nums.size(); i++) {
            sQueue.push(nums[i]);
            sQueue.pop();
            output.push_back(sQueue.getMax());
        }
        return output;
    }
};