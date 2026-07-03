class MyStack {
private:
    vector<int>arr;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        arr.push_back(x);
    }
    
    int pop() {
        if(empty())return -1;
        int topElement = top();
        arr.pop_back();
        return topElement;
    }
    
    int top() {
        if(empty())return -1;
        return arr[arr.size()-1];
    }
    
    bool empty() {
        return arr.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */