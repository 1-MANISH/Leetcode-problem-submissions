
struct Data{
    vector<int>point;
    float distance;
};
class Solution {
public:
    static bool compare(Data &a,Data &b){
        if(a.distance==b.distance){
            if(a.point[0]==b.point[0]) return a.point[1]>b.point[1];
            else return a.point[0]>b.point[0];
        }
        else return a.distance<b.distance;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<Data>distance;
        for(auto &point:points){
            int x = point[0],y=point[1];
            float dist = sqrt(x*x+y*y);
            distance.push_back({point,dist});
        }
        sort(distance.begin(),distance.end(),compare);
        vector<vector<int>>answer;
        for(int i = 0 ; i < k ; i++){
            answer.push_back(distance[i].point);
        }
        return answer;
    }
};