class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int start = 0, end = arr.size()-1;
        while(start<end){
            int mid = start+(end-start)/2;
            int sideElements = mid-start;

            if(sideElements & 1){
                // odd elements in side
                if(arr[mid]==arr[mid-1]) // right me avaible
                    start=mid+1;
                else if(arr[mid]==arr[mid+1]) // left me available
                    end=mid-1;
                else
                    return arr[mid];
            }else{
                // even elements in side
                if(arr[mid]==arr[mid-1])//left me available
                    end=mid-2;
                else if(arr[mid]==arr[mid+1])// right me available
                    start=mid+2;
                else
                    return arr[mid];
            }
        }

        return arr[start];
    }
};

/*
n = 9
1,1,2,3,3,4,4,8,8
s = 0 e = 8 | m=4
1,1,2
s = 0 e = 2 | m=1
s = 2 | e = 2 
2
return arr[start]
*/