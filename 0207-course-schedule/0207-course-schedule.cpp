class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // topo sorted possible  -  then able to complete the course
        vector<int>adjList[numCourses];
        vector<int>indegree(numCourses,0);
        for(auto &edge:prerequisites){
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            indegree[v]++;
        }

        // topo sort logic
        queue<int>q;
        for(int node = 0 ; node < numCourses;node++){
            if(indegree[node]==0)q.push(node);
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(int &adjNode:adjList[node]){
                indegree[adjNode]--;
                if(indegree[adjNode]==0){
                    q.push(adjNode);
                }
            }
        }

        return ans.size()==numCourses;
    }
};