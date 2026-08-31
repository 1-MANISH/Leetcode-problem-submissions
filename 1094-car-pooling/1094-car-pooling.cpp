struct Data {
    int location;
    int passengers;// pickup = +num, drop = -num  
};

class Solution {
    static bool compare(Data &a,Data &b){
        if(a.location==b.location){
            return a.passengers<b.passengers;
        }
        return a.location<b.location;
    }
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<Data>events;
        for(auto &trip:trips){
            Data d1,d2;
            d1.location=trip[1];
            d1.passengers=trip[0];
            d2.location=trip[2];
            d2.passengers=-trip[0];
            events.push_back(d1);
            events.push_back(d2);
        }
        sort(events.begin(),events.end(),compare);
        int passengers =  0;
        for(auto &event:events){
            passengers+=event.passengers;
            if(passengers>capacity)return false;
        }
        return true;
    }
};