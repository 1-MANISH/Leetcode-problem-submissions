class Solution {
    long long coverIsland(int row,int col,vector<vector<bool>>&visited,vector<vector<int>>&grid){
        // every time we covering one complete islands
        visited[row][col]=true;
        queue<pair<int,int>>q;
        q.push({row,col});
         long long sum = 0;
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            sum+=0LL+grid[r][c];
            // check adjacent land which can be part of this island
            int rows[4] = {0,-1,0,+1};
            int cols[4] = {-1,0,+1,0};
            for(int i = 0 ;i < 4;i++){
                int newRow = r+rows[i];
                int newCol = c+cols[i];
                if(newRow>=0 and newRow< grid.size() and newCol>=0 and newCol < grid[0].size() and grid[newRow][newCol]!=0 and !visited[newRow][newCol]){
                    visited[newRow][newCol]=true;
                    q.push({newRow,newCol});
                }   
            }
        }
        return sum;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid[0].size(),false));
        for(int row =0 ;row< grid.size();row++){
            for(int col =0 ; col < grid[0].size();col++){
                if(grid[row][col]!=0 and !visited[row][col]){
                    long long sum = coverIsland(row,col,visited,grid);
                    if(sum%k==0)count++;
                }
            }
        }
        return count;
    }
};