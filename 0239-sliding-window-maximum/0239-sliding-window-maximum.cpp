// MAX STACK + queue with 2 stack
class AggregateQueue{
    public:
    stack<pair<int,int>>inStack,outStack;//{ele,tillNowMax}

    AggregateQueue(){};
    // o(1)
    void push(int element){
        if(inStack.empty())inStack.push({element,element});
        else inStack.push({element,max(element,inStack.top().second)});
    }
    // Amortized -> avergae -O(1)
    void pop(){
        if(outStack.empty()){
            while(!inStack.empty()){
                if(outStack.empty())outStack.push({inStack.top().first,inStack.top().first});
                else outStack.push({inStack.top().first,max(inStack.top().first,outStack.top().second)});//{ele,max(ele,oldMax)}
                inStack.pop();
            }
        }
        outStack.pop();// unneccerry removal - [i-k+1,i]- removing before wala
    }
    //o(1)
    int getMax(){
        if(inStack.empty())return outStack.top().second;
        if(outStack.empty())return inStack.top().second;
        return max(inStack.top().second,outStack.top().second);
    }

};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>output;
        AggregateQueue sQueue;
        for(int i = 0 ; i< k ; i++) sQueue.push(nums[i]);
        output.push_back(sQueue.getMax());
        for(int i = k ; i < nums.size(); i++){
            sQueue.push(nums[i]);// add - new one
            sQueue.pop();// remove un-neeccessery
            output.push_back(sQueue.getMax());// getting window max
        }
        return output;
    }
};