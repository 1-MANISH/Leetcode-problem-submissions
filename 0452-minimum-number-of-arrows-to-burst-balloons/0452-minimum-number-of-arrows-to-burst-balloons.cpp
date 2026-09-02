class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int arrows_needed = 0 ;
        sort(points.begin(),points.end());
        int start = points[0][0] ,  end = points[0][1] ,currentStart,currentEnd;
        int index = 1 , n = points.size();
        while(index<n){
            currentStart = points[index][0] ,  currentEnd = points[index][1];
            if(start<=currentStart && currentStart<=end){
                  start=max(start,currentStart);
                  end=min(end,currentEnd);
            }else{
                arrows_needed++; 
                start=currentStart;
                end=currentEnd;
            }
            
            index++;
        }
        return arrows_needed+1;
    }
};