class Solution {
public:
    // [ [1,3], [6,10], [16,19]]  [0,0]
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>>output;
        int s1 = newInterval[0] ,  e1 = newInterval[1] ,s2,e2;
        int index=0 , overlap = 0 ;
        while(index<n){
            s2 = intervals[index][0] ,  e2 = intervals[index][1];
            if(max(s1,s2)<=min(e1,e2)){
                s1=min(s1,s2);
                e1=max(e1,e2);
                overlap=1;
            }else{
                //  overlap done - 
                // either - no further overlap also - need to insert here
                if((s1 < s2 && e1 < e2 && overlap!=10) || overlap==1 ){
                    output.push_back({s1,e1});
                    overlap=10;
                }
                output.push_back({s2,e2});
            }
            index++;
        }
        if(n==0 || overlap!=10 ){
            output.push_back({s1,e1});
        }
        return output;
    }
};