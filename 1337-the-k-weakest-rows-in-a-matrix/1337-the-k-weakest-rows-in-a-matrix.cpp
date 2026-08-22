template <typename T>
using MaxHeap = priority_queue<T>;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        MaxHeap<pair<int,int>>mxHeap;//{solderCount,rowIndex};
        vector<int>weekestRows(k);
        int m = mat.size() , n =mat[0].size();
        for(int i = 0 ;i < m ; i++){
            int solderCount=0;
            for(int j = 0 ; j < n ; j++)solderCount+=mat[i][j];
            mxHeap.push({solderCount,i});
            if(mxHeap.size()>k){
                mxHeap.pop();
            }
        }
        for(int i = k-1 ; i>=0 ; i--){
            weekestRows[i]=mxHeap.top().second;
            mxHeap.pop();
        }
        return weekestRows;
    }
};