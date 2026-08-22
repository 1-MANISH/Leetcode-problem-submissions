template <typename T>
using MaxHeap = priority_queue<T>;

template <typename T>
using MinHeap = priority_queue<T,vector<T>,greater<T>>;

class MedianFinder {
private:
    MaxHeap<int>mx_heap;
    MinHeap<int>mn_heap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mx_heap.push(num);
        mn_heap.push(mx_heap.top());
        mx_heap.pop();
        if(mx_heap.size()<mn_heap.size()){
            mx_heap.push(mn_heap.top());
            mn_heap.pop();
        }
    }
    
    double findMedian() {
        if(mx_heap.size()>mn_heap.size())
            return mx_heap.top();
        else return  (double) ( ( mx_heap.top() + (double) mn_heap.top()) /2 );
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */