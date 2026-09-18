const int N = 5e2;
int dp[N][N];

class Solution {
    int solve(int i,int j,string &s){
        // base case
        if(i>=j){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int ans = 0;
        // if both i'th and j'th char same then no need to do nayhting check further
        if(s[i]==s[j]){
            ans = solve(i+1,j-1,s);
        }else{

            // either add at ith place
            int ans1 = 1 + solve(i,j-1,s);

            // either add at jth place
            int ans2 = 1 + solve(i+1,j,s);

            ans = min(ans1,ans2);
        }
        return dp[i][j] = ans;
    }
public:
    int minInsertions(string s) {
        memset(dp,-1,sizeof dp);
        return solve(0,s.size()-1,s);
    }
};