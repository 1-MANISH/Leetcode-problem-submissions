class Solution {
public:
    vector<int> prevSmaller(vector<int>&arr,int &n){
        stack<int>st;
        vector<int>output(n,-1);// -1 means expansion till begin
        for(int i = 0 ;i < n ; i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                output[i]=-1;
            }else{
                output[i] = st.top();
            }
            st.push(i);
        } 
        return output;
    }
    vector<int> nextSmaller(vector<int>&arr,int &n){
        stack<int>st;
        vector<int>output(n,n);//n means expanstion till end
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                output[i]=n;
            }else{
                output[i]=st.top();
            }
            st.push(i);
        }
        return output;
    }
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0 , n = heights.size();
        vector<int>pSmaller = prevSmaller(heights,n);
        vector<int>nSmaller = nextSmaller(heights,n);
        for(int i  = 0 ; i < n ; i++){
            int h = heights[i];
            int w = nSmaller[i]-pSmaller[i]-1;
            ans = max(ans,w*h);
        }
        return ans;
    }
};