
const int WHITE = 0;
const int BLUE = -1;
const int RED = 1;
class Solution {

    bool isBip(int node,vector<int> adj[],vector<int>&color,int c){
        queue<int>q;
        q.push({node});
        color[node]=RED;

        while(!q.empty()){
            int c_node = q.front();
            q.pop();

            for(int &neb:adj[c_node]){
                if(color[neb]==WHITE){ //not visited
                    q.push(neb);
                    color[neb] = color[c_node]==RED ? BLUE : RED;
                }else if(color[neb]==color[c_node]){ // conflict with 
                    return false;
                }
            }
       }
        return true;

    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>color(n+1,WHITE);
        vector<int>adjList[n+1];
        for(auto &edge:dislikes){
            int u = edge[0] , v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        for(int node = 1; node <= n ;  node++){
            if(color[node]==WHITE){
                bool ans = isBip(node,adjList,color,RED);
                if(ans==false)return false;
            }
        }

        return true;
    }
};