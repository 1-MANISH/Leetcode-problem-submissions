class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        while(arr[0]!=arr[arr[0]]){
            swap(arr[0],arr[arr[0]]);
        }
        return arr[0];
        
    }
};