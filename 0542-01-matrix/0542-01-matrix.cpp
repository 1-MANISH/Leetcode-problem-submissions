class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size() ,  m = mat[0].size();
        // push all 1 into queue - with initial distance 0 as 1 from 1 itself 0
        queue<pair<int,pair<int,int>>>q;//{dist,{i,j}}
        vector<vector<int>>distance(n,vector<int>(m,0));
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j]==0){
                    q.push({0,{i,j}});
                    visited[i][j]=true;
                    // distance[i][j]=0; no need 
                }
            }
        }
        
        // now calculate best one
        while(!q.empty()){
            auto[r,c] = q.front().second;
            int dist = q.front().first;
            q.pop();
            
            // now adjacent node
            int rows[4] = {0,-1,0,+1};
            int cols[4] = {-1,0,+1,0};
            
            for(int i = 0 ; i < 4 ; i++){
                int n_r=r+rows[i];
                int n_c=c+cols[i];
                if(n_r>=0 and n_r<n and n_c>=0 and n_c<m and mat[n_r][n_c]==1 and !visited[n_r][n_c]){
                    q.push({dist+1,{n_r,n_c}});
                    visited[n_r][n_c]=true;
                    distance[n_r][n_c]=dist+1;
                }
            }
        }
        
        return distance;
    }
};