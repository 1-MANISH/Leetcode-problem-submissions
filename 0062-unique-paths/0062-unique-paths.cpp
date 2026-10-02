const int N = 1e2;
const int M = 1e2;

int dp[N][M];

class Solution {

    int solve(int i,int j,int &n,int &m){

        //base case
        if(i==n-1 and j==m-1){
            return 1;
        }
        if(i>=n or j>=m){
            return 0;
        }

        if(dp[i][j]!=-1)return dp[i][j];

        // right 
        int ans1 = solve(i,j+1,n,m);
        // down
        int ans2 = solve(i+1,j,n,m);

        return dp[i][j] = ans1+ans2;
    }

public:
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,n,m);
    }
};