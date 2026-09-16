class Solution {
public:
    string convert(string s, int numRows) {

        // base case
        if(numRows == 1)
            return s;

        int n = s.size();
        int index = 0;
        bool direction  = true; // true -> down | false -> up

        vector<string>ans(numRows);

        for(int i = 0 ; i < numRows && index < n ; i++){
            ans[i]+=s[index++];
        }


        direction = !direction;

        while(index < n){

            if(index >= n)
                break;
            
            if(direction){
                for(int i = 1 ; i < numRows && index < n ; i++){
                    ans[i]+=s[index++];
                }
            }
            else{
                for(int i = numRows-2 ; i>=0 && index< n ; i--){
                    ans[i]+=s[index++];
                }
            }
            direction = !direction;
            
        }

        string rejult = "";
        for(auto str:ans){
            rejult+=str;
        }

        return rejult;
  
    }
};