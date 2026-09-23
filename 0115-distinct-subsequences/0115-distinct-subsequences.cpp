const int N = 1e3;
int dp[N][N];

class Solution {

    int solve(int i ,int j , string &s,string &t){

        // base case
        if(j==t.size())return 1;

        if(i==s.size())return 0;

        if(dp[i][j]!=-1)return dp[i][j];
        // not takeshort

        int ans1  = solve(i+1,j,s,t);

        // take it
        int ans2 = 0 ;

        if(s[i]==t[j]){
            ans2 = solve(i+1,j+1,s,t);
        }

        return dp[i][j] =ans1+ans2;
    }
public:
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,s,t);
    }
};