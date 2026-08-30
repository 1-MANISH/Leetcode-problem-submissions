class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int s1 = intervals[0][0] ,  e1 = intervals[0][1] , index = 1, n = intervals.size();
        vector<vector<int>>output;
        while(index<n){
            int s2 = intervals[index][0] , e2 = intervals[index][1];
            // overlap 
            if(max(s1,s2)<=min(e1,e2)){
                e1 = max(e1,e2);
            }else{
                output.push_back({s1,e1});
                s1=intervals[index][0];
                e1=intervals[index][1];
            }
            index++;
        }
        output.push_back({s1,e1});
        return output;
    }
};