class MyQueue {
public:
    int max_size=1e5;
    int _size=0,s=-1,e=-1;
    int *arr =  new int[max_size];
    MyQueue() {
        
    }
    
    void push(int x) {
        if(_size==max_size)return;
        if(empty()){
            s=e=0;
        }else{
            e = (e+1)%max_size;
        }
        arr[e]=x;
        _size++;
    }
    
    int pop() {
        if(empty())return -1;
        int ele = arr[s];
        s = (s+1)%max_size;
        _size--;
        return ele;
    }
    
    int peek() {
        if(empty())return -1;
        return arr[s];
    }
    
    bool empty() {
        return _size==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */