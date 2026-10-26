class Solution {
private:
    bool isCycle(int row,int col,vector<vector<char>>&grid,vector<vector<bool>>&visited){
        int n = grid.size() , m = grid[0].size();
        // using bfs
        queue<pair<pair<int,int>,pair<int,int>>>q;
        q.push({{row,col},{-1,-1}});
        visited[row][col]=true;
        while(!q.empty()){
            auto [r,c] = q.front().first;
            auto [pr,pc] = q.front().second;
            q.pop();

            // checking adjacent
            int rows[4] = {0,-1,0,+1};
            int cols[4] = {-1,0,+1,0};
            for(int i = 0  ; i < 4 ;i++){
                int n_r = r + rows[i];
                int n_c = c + cols[i];
                if(n_r>=0 and n_r<n and n_c>=0 and n_c<m and grid[n_r][n_c]==grid[r][c] and !visited[n_r][n_c]){
                    q.push({{n_r,n_c},{r,c}});
                    visited[n_r][n_c]=true;
                }else if(n_r>=0 and n_r<n and n_c>=0 and n_c<m and grid[n_r][n_c]==grid[r][c] and visited[n_r][n_c]){
                    if(n_r != pr and n_c != pc)return true;
                }
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i = 0 ; i < n ; i++){
            for(int j =0 ; j < m ; j++){
                if(!visited[i][j]){
                    bool check = isCycle(i,j,grid,visited);
                    if(check)return true;
                }
            }
        }
        return false;
    }
};