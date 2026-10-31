
const int WHITE = 0;
const int BLUE = -1;
const int RED = 1;
class Solution {

    bool isBip(int node,vector<vector<int>>& adj,vector<int>&color,int c){
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
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int>color(n,WHITE);

        for(int node = 0; node < n ;  node++){
            if(color[node]==WHITE){
                bool ans = isBip(node,adj,color,RED);
                if(ans==false)return false;
            }
        }

        return true;
    }
};