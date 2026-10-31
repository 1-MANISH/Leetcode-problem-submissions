
const int WHITE = 0;
const int BLUE = -1;
const int RED = 1;
class Solution {

    bool isBip(int node,vector<vector<int>>& adj,vector<int>&color,int c){
        color[node]=c;

        for(int &neb:adj[node]){
            if(color[neb]==WHITE){
                bool ans = isBip(neb,adj,color,-1*c);
                if(ans==false)return false;
            }else if(color[neb]==color[node]){
                return false;
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
                if(!ans)return false;
            }
        }

        return true;
    }
};