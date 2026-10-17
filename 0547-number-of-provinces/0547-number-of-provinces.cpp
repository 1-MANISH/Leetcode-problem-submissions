class Solution {

    void bfs(int &node,vector<bool>&visited,vector<int> adjList[]){
    
        queue<int>q;
        q.push(node);
        visited[node]=true;
        
        while(!q.empty()){
            int c_node = q.front();
            q.pop();
            // insert it adjacenet node
            for(auto &adjNode:adjList[c_node]){
                if(!visited[adjNode]){
                    visited[adjNode]=true;
                    q.push(adjNode);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjList[n];
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n; j++){
                if(isConnected[i][j]==1 and i!=j){
                    adjList[i].push_back(j);
                }
            }
        }
        int count = 0;
        vector<bool>visited(n,false);
        for(int node = 0 ; node < n ; node++){
            if(!visited[node]){
                bfs(node,visited,adjList);
                count++;
            }
        }
        return count;
    }
};