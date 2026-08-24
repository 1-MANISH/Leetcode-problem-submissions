struct Data{
    vector<int>point;
    float distance;
};
struct CompareFunction{
    bool operator()(const Data&a,const Data&b){
        if(a.distance==b.distance){
           if(a.point[0]==b.point[0])return a.point[1]>b.point[1];
           else  return a.point[0]>b.point[0];
        }
        return a.distance<b.distance;// max distanct at top
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<Data,vector<Data>,CompareFunction>maxHeap;//based on distance

        for(auto point:points){
            float x = point[0], y = point[1];
            float origin_distance = sqrt(x*x + y*y);
            maxHeap.push({point,origin_distance});
            if(maxHeap.size()>k){
                maxHeap.pop();// maximum distance point removal
            }
        }
        vector<vector<int>>answer;// points closest to origin as per distance
        while(!maxHeap.empty()){
            answer.push_back(maxHeap.top().point);
            maxHeap.pop();
        }
        return answer;
    }
};