class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int>st;
        vector<int>output(n,-1);
        vector<int>flag(n,false);// for which element greator founds
        for(int i = n-1; i>=0 ;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty()){
                output[i]=-1;
            }
            else{
                flag[i]=true;
                output[i]=st.top();
            }
            st.push(nums[i]);
        }
        int j = n-1;
        while(j>=0 && !st.empty()){
            if(flag[j]){
                j--;
                continue;
            }
            while(!st.empty() && st.top()<=nums[j]){
                st.pop();
            }
            if(st.empty())output[j]=-1;
            else output[j]=st.top();
            j--;
        }
        return output;
    }
};