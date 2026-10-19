class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int>rowMn;
        vector<int>colMx;
        for(int row = 0 ;row < matrix.size();row++){
            int rowMin = INT_MAX;
            for(int col=0;col<matrix[0].size();col++)rowMin=min(rowMin,matrix[row][col]);
            rowMn.push_back(rowMin);
        }
        for(int col = 0 ;col < matrix[0].size();col++){
            int colMax = INT_MIN;
            for(int row=0;row<matrix.size();row++)colMax=max(colMax,matrix[row][col]);
            colMx.push_back(colMax);
        }
        vector<int>output;
        for(int row = 0;row < matrix.size();row++){
            int rowMin = rowMn[row];
            for(int col=0;col<matrix[0].size();col++){
                int colMax = colMx[col];
                if(rowMin==colMax and matrix[row][col]==rowMin) output.push_back(matrix[row][col]);
            }
        }
        return output;
    }
};