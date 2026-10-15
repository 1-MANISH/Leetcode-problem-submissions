class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // there is catch that if person who is town judge then  -  adjList[town_jugde] = {} empty

        vector<int> adjList[n+1];

        for(auto &edge:trust){
            int u = edge[0] , v = edge[1];
            adjList[u].push_back(v);
        }
        for(int node = 1 ; node <=n ; node++){
            if(adjList[node].size()==0){
                int answer = 0 ; // just to check that everyone is trusting our town judge or not
                for(auto &t:trust){
                    if(t[1]==node)answer++;
                }
                if(answer==n-1)return node;
            };
        }
        return -1;
    }
};