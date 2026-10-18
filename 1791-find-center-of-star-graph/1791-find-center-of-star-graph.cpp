class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>adjList[n+2];
        for(auto &edge:edges){
            int u = edge[0] ,v =edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        for(int node = 1 ; node <= n+1; node++){
            if(adjList[node].size()>1)return node;
        }
        return -1;
    }
};