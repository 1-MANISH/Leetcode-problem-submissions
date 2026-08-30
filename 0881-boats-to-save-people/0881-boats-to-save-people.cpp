class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i = 0 , j = people.size()-1 , count = 0 ;
        while(i<j){
            int currentPairWeight=people[i]+people[j];
            if(currentPairWeight<=limit){
                count++;
                i++;
                j--;
            }else{
                count++;
                j--;
            }
        }
        if(i==j)count++;
        return count;
    }
};