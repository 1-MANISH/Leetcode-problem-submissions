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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>newIntervals;
        int n = intervals.size();
        int s1,s2,e1,e2;
        s2=newInterval[0];
        e2=newInterval[1];
        for(int i = 0 ; i< n ; i++){
            s1=intervals[i][0];
            e1=intervals[i][1];
            if(max(s1,s2)<=min(e1,e2)){
                if(s1<s2){
                    newIntervals.push_back({s1,e1});
                    newIntervals.push_back({s2,e2});
                }
                else if(s1>s2){
                    newIntervals.push_back({s2,e2});
                    newIntervals.push_back({s1,e1});
                }
                else if(e1<e2){
                    newIntervals.push_back({s1,e1});
                    newIntervals.push_back({s2,e2});
                }
                else {
                    newIntervals.push_back({s2,e2});
                    newIntervals.push_back({s1,e1});
                }
                i++;
                for(;i<n;i++)
                    newIntervals.push_back({intervals[i][0],intervals[i][1]});
                break;
            }else {
                if(i+1==n){
                    if(s1<s2){
                        newIntervals.push_back({s1,e1});
                        newIntervals.push_back({s2,e2});
                    }
                    else if(s1>s2){
                        newIntervals.push_back({s2,e2});
                        newIntervals.push_back({s1,e1});
                    }
                    else if(e1<e2){
                        newIntervals.push_back({s1,e1});
                        newIntervals.push_back({s2,e2});
                    }
                    else {
                        newIntervals.push_back({s2,e2});
                        newIntervals.push_back({s1,e1});
                    }
                }
                else {
                    newIntervals.push_back({s1,e1});
                }
            }
        }
        if(n==0)newIntervals.push_back({s2,e2});
        return merge(newIntervals);
    }
};