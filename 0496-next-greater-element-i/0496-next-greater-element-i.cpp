class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int>mapping;
        stack<int>st;
        vector<int>output(n,-1);
        for(int i = n-1 ; i >= 0 ; i--){
            mapping[nums2[i]]=i;// as numbers are unique
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                output[i]=-1;
            }else{
                output[i]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(auto &ele:nums1){
            ans.push_back(output[mapping[ele]]);
        }
        return ans;
    }
};