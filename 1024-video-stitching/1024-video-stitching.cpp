class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        // skipping overlapping 
        sort(clips.begin(),clips.end());
        int endPoint = 0 , count = 0  ,index =  0 , n = clips.size();
        while(index<n){
            int farthest = -1;
            while(index<n and clips[index][0]<=endPoint){
                farthest = max(farthest,clips[index][1]);
                index++;
            }
            if(farthest==-1)return -1;
            count++;
            if(farthest>=time)return count;
            endPoint = farthest;
           
        }
        if(endPoint<time)return -1;
        return count;
    }
};