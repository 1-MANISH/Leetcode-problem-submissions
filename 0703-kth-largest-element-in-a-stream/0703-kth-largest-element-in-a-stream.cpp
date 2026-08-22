template <typename T>
using MinHeap = priority_queue<T,vector<T>,greater<T>>;

class KthLargest {
    int k;
    MinHeap<int>minHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int score:nums){
            minHeap.push(score);
            if(minHeap.size()>k)minHeap.pop();
        }
    }
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size()>k)minHeap.pop();
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */