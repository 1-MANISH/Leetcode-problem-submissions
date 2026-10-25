class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n  =  grid.size() ,  m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        // first start with all rotten oranges -  as move first
        queue<pair<int,int>>q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        
        int ans = 0 ;
        // now paralley trying to rotten all possible oranges with each unit time ,gradually increasing
        while(!q.empty()){
            int c_size = q.size();
            for(int i = 1 ; i <= c_size ; i++){
                auto[r,c]=q.front();
                q.pop();

                // adjcent become rotten
                int rows[4] = {0,-1,0,+1};
                int cols[4] = {-1,0,+1,0};
                for(int index = 0 ; index < 4 ; index++){
                    int n_r = r + rows[index];
                    int n_c = c + cols[index];
                    if(n_r>=0 and n_r < n and n_c>=0 and n_c<m and grid[n_r][n_c]==1 and !visited[n_r][n_c]){
                        q.push({n_r,n_c});
                        visited[n_r][n_c]=true;
                    }
                }
            }
            ans++;
        }

        // now check every fresh orange is rottened or not
        for(int i = 0  ; i < n ; i++){
            for(int j = 0 ;j < m ; j++){
                if(grid[i][j]==1 and !visited[i][j])return -1;
            }
        }
        return ans? ans-1 : 0;
    }
};