class Solution {

public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        queue<pair<int,int>>q;
        for(int row = 0; row < grid.size();row++){
            for(int col = 0 ; col < grid[0].size() ; col++){
                if(grid[row][col]==2){
                    visited[row][col]=true;
                    q.push({row,col});
                }
            }
        }
        int ans = 0;

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0 ; i < size ; i++)
            {
                auto[r,c]=q.front();
                q.pop();

                // adjacent
                int rows[4] = {0,-1,0,+1};
                int cols[4] = {-1,0,+1,0};
                for(int i = 0 ; i < 4;i++)
                {
                    int new_r = r+rows[i];
                    int new_c = c+cols[i];
                    if(new_r>=0 and new_r < grid.size() and new_c >=0 and new_c < grid[0].size() and grid[new_r][new_c]==1 and !visited[new_r][new_c])
                    {
                        visited[new_r][new_c]=true;
                        q.push({new_r,new_c});
                    }
                }
            }
            ans++;
        }  

        // if not possible to rotten someone
        for(int row = 0; row < grid.size();row++){
            for(int col = 0 ; col < grid[0].size() ; col++){
                if(grid[row][col]==1 and !visited[row][col]) return -1;
            }
        }
        
        return ans ? ans-1 : ans;
    }
};