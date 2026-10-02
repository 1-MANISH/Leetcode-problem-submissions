class Solution {
    bool isPal(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        
        int n  = s.size();
        int start = 0 , maxLen = 0;

        for(int i  = 0 ; i < n  ; i++){
            for(int j = i; j<n ; j++){
                if(isPal(i,j,s)){
                    if(j-i+1 > maxLen){
                        start = i;
                        maxLen = j-i+1;
                    }
                }
            }
        }

        return s.substr(start,maxLen);
    }
};