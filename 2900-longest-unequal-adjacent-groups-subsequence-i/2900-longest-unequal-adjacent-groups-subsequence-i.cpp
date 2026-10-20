const int N = 100;
int dp[N+10][N+10];

class Solution {
    int solve(int index,int prevIndex,vector<string>&words,vector<int>& groups){
        // base case
        if(index==words.size()){
            return 0;
        }
        
        if(dp[index][prevIndex]!=-1) return dp[index][prevIndex];
        // not take it
        int ans1 = solve(index+1,prevIndex,words,groups);

        // take it - if differ group index
        int ans2 = 0;
        if(prevIndex==words.size() or groups[index]!=groups[prevIndex]){
            ans2 = 1 + solve(index+1,index,words,groups);
        }
        return dp[index][prevIndex] = max(ans1,ans2);
    }
    void recover(int index,int prevIndex,vector<string>&words,vector<int>& groups,vector<string>&output){
        // base case
        if(index==words.size()){
            return;
        }
        
        
        // not take it
        int ans1 = solve(index+1,prevIndex,words,groups);

        // take it - if differ group index
        int ans2 = 0;
        if(prevIndex==words.size() or groups[index]!=groups[prevIndex]){
            ans2 = 1 + solve(index+1,index,words,groups);
        }
        int ans = max(ans1,ans2);
        if(ans==ans1){
           recover(index+1,prevIndex,words,groups,output); 
        }else{
            output.push_back(words[index]);
            recover(index+1,index,words,groups,output); 
        }
    }
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        memset(dp,-1,sizeof dp);
        int ans = solve(0,words.size(),words,groups);
        vector<string>output;
        recover(0,words.size(),words,groups,output);
        return output;
    }
};