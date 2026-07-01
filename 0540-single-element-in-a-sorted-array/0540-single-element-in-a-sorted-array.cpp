class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int start = 0, end = arr.size()-1;
        while(start<end){
            int mid = start+(end-start)/2;
            int sideElements = mid-start;

            if(sideElements & 1){
                // odd elements in side
                if(arr[mid]==arr[mid-1])
                    start=mid+1;
                else if(arr[mid]==arr[mid+1])
                    end=mid-1;
                else
                    return arr[mid];
            }else{
                // even elements in side
                if(arr[mid]==arr[mid-1])
                    end=mid-2;
                else if(arr[mid]==arr[mid+1])
                    start=mid+2;
                else
                    return arr[mid];
            }
        }

        return arr[start];
    }
};