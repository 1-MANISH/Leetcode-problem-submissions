class StockSpanner {
public:
    int index = 0 ;
    stack<pair<int,int>>st;//element,index
    StockSpanner() {
        this->index=0;
    }
    int next(int price) {
        int span  = index;
        while(!st.empty() && st.top().first<=price){
            st.pop();
        }
        if(!st.empty()){
            span=index-st.top().second;
        }else{
            span=index+1;
        }
        st.push({price,index});
        index++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */