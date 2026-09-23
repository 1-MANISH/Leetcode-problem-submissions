const int N = 1e3;
int dp[N][N];


// path recovery mechnism

class Solution {
    string result = "";
    int solve(int i,int j,string &s,string &t){
        // base case

        if(i==s.size()){
            return t.size() - j ;
        }
        if(j==t.size()){
            return s.size() - i ;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = 0 ;

        // if both char at current position equals means -  need to take it
        if(s[i]==t[j]){
            ans = 1 + solve(i+1,j+1,s,t);
        }else{
            // take it from s -  means add this from s and look other part of [.  s] and t
            int ans1 = 1 + solve(i+1,j,s,t);

            // take it from t
            int ans2 = 1 + solve(i,j+1,s,t);

            ans = min(ans1,ans2);
        }

        return dp[i][j] =  ans;
    }
    
    void recover(int i,int j,string &s,string &t){
        // base case

        if(i==s.size()){
            result+=t.substr(j);
            return;
        }
        if(j==t.size()){
            result+=s.substr(i);
            return;
        }

        int ans = 0 ;

        // if both char at current position equals means -  need to take it
        if(s[i]==t[j]){
            ans = 1 + solve(i+1,j+1,s,t);
            result.push_back(s[i]); // means we are adding this char to result
            recover(i+1,j+1,s,t);
        }else{
            // take it from s -  means add this from s and look other part of [.  s] and t
            int ans1 = 1 + solve(i+1,j,s,t);

            // take it from t
            int ans2 = 1 + solve(i,j+1,s,t);

            ans = min(ans1,ans2);

            if(ans==ans1){
                // means we are taking from  s
                result.push_back(s[i]);
                recover(i+1,j,s,t);
            }
            else{
                result.push_back(t[j]);
                recover(i,j+1,s,t);
            }
        }

    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        memset(dp,-1,sizeof dp);
        solve(0,0,str1,str2);
        recover(0,0,str1,str2);
        return result;
    }
};