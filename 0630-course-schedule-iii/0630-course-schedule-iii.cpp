template<typename T>
using MaxHeap = priority_queue<T>;

class Solution {

    bool static compare(vector<int>&a,vector<int>&b){
        if(a[1]==b[1]){
            return a[0]<b[0];// short duration
        }else{
            return a[1]<b[1];// easly finish 
        }
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        //{duration,lastDay/deadline}
        sort(courses.begin(),courses.end(),compare);
        // sort based on lastDay -  means early finish course comes
        // first if lastDay equal then a short duration
        int tillNowDaysToken = 0 , n =  courses.size();
        MaxHeap<int>maxHeap;//{duration}
        for(int i = 0 ; i < n ; i++){
            tillNowDaysToken+=courses[i][0];

            maxHeap.push(courses[i][0]);

            if(tillNowDaysToken>courses[i][1]){// last day se pahlee yeh job finish nhi hogi so remove job which taking longer duration
                tillNowDaysToken-=maxHeap.top();// remove maximum taking duration
                maxHeap.pop();

            }
            
        }
        return maxHeap.size();
    }
};