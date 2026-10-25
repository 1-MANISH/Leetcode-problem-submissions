class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n  =  grid.size() ,  m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        // first start with all rotten oranges -  as move first
        queue<pair<int,pair<int,int>>>q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j]==2){
                    q.push({0,{i,j}});
                    visited[i][j]=true;
                }
            }
        }
        
        int timer = 0 ;
        // now paralley trying to rotten all possible oranges with each unit time ,gradually increasing
        
                
        int rows[4] = {0,-1,0,+1};
        int cols[4] = {-1,0,+1,0};
        while(!q.empty()){
         
            int t = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();
            timer = max(timer,t);

            // its adjacent element
            for(int index = 0 ; index < 4 ; index++){
                int n_r = r + rows[index];
                int n_c = c + cols[index];
                if(n_r>=0 and n_r < n and n_c>=0 and n_c<m and grid[n_r][n_c]==1 and !visited[n_r][n_c]){
                    q.push({t+1,{n_r,n_c}});
                    visited[n_r][n_c]=true;
                }
            }
        }

        // now check every fresh orange is rottened or not
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ;j < m ; j++){
                if(grid[i][j]==1 and visited[i][j]==0)return -1;
            }
        }
        return timer;
    }
};