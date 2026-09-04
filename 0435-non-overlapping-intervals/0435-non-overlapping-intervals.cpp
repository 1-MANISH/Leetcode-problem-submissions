#include<bits/stdc++.h>
class Solution {

    // end point ke basis par sorting  - increasing order
    bool static compare(vector<int> &a,vector<int> &b){
        if(a[1]==b[1]){
            return a[0]<b[0];
        }else{
            return a[1]<b[1];
        }
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // need to maximize -intervals to be there
        sort(intervals.begin(),intervals.end(),compare);
        int index=1 ,  endPoint = intervals[0][1] ,  canBeThere=1 ,  n = intervals.size();

        while(index<n){
            if(intervals[index][0]>=endPoint){
                endPoint = intervals[index][1];
                index++;
                canBeThere++;
            }else{
                index++;
            }
        }

        return n - canBeThere;// number of removed intervals

    }
};