class Solution {

    bool bfs(int node,vector<int>adj[],vector<bool>&visited, int &destination){

        queue<int>q;
        visited[node]=true;
        q.push(node);

        while(!q.empty()){
            int c_node = q.front();
            q.pop();

            if(c_node==destination){
                return true;
            }
            for(auto &adjNode:adj[c_node]){
                if(!visited[adjNode]){
                    visited[adjNode]=true;
                    q.push(adjNode);
                }
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
       
        vector<int>adjList[n];
        for(auto &edge:edges){
            int u  = edge[0] , v =edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        vector<bool>visited(n,false);

        return bfs(source,adjList,visited,destination);

    }
};