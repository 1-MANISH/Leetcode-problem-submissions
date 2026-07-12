class Solution {
public:

    //M. maximum Rectangle 
    vector<int> prevSmaller(vector<int>&arr,int &n){
        vector<int>output(n,-1);
        stack<int>st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                output[i]=-1;
            }else{
                output[i]=st.top();
            }
            st.push(i);
        }
        return output;
    }

    vector<int> nextSmaller(vector<int>&arr,int &n){
        vector<int>output(n,n);
        stack<int>st;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                output[i]=n;
            }else{
                output[i]=st.top();
            }
            st.push(i);
        }
        return output;
    }
    // optimal
    int largestRectangleOptimalInHistogram(vector<int>&bars,int &n){
        int ans = 0;
        vector<int>pSmall = prevSmaller(bars,n);
        vector<int>nSmall = nextSmaller(bars,n);
        for(int i = 0; i < n ; i++){
            int h = bars[i];
            int w = nSmall[i]-pSmall[i]-1;
            int currentAns = w*h;
            ans = max(ans,currentAns); 
        }
        return ans;
    }

    int maxRectangle(vector<vector<int>>&matrix,int &n,int &m){
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans,largestRectangleOptimalInHistogram(matrix[i],m));
        }
        return ans;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size() , m = matrix[0].size();

        vector<vector<int>>matrix2(n,vector<int>(m));
         for(int i = 0 ; i < n  ; i++){
            for(int j = 0 ; j < m ; j++){
                matrix2[i][j] = matrix[i][j]-'0';
            }
        }
        for(int i = 0  ; i < n  ; i++){
            for(int j = 0 ;j < m ; j++){
                if(i!=0){
                    if(matrix2[i][j]==0)
                        matrix2[i][j]=0;
                    else
                        matrix2[i][j] = matrix2[i-1][j]+matrix2[i][j];
                }
            }
        }
        return maxRectangle(matrix2,n,m);
    }
};