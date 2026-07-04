
class MinStack {
private:
    stack<pair<int,int>>st;//<value,minTillNow>
public:
    MinStack() {

    }
    void push(int value) {
        if(st.empty())
            st.push({value,value});
        else
            st.push({value,min(value,getMin())});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.empty()?-1: st.top().first;
    }

    int getMin() {
        return st.empty()?-1: st.top().second;
    }

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */