class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<int>p_odd(n,0),p_even(n,0);
        if(nums[0]&1)p_odd[0]=1;
        else p_even[0]=1;
        for(int i = 1 ; i < n ; i++){
            p_odd[i]=p_odd[i-1]+(nums[i]&1 ?1:0);
            p_even[i]=p_even[i-1]+(nums[i]&1 ?0:1);
        }
        int pairs = 0;
        long long  p = a ,q = b;
        for(int i = 0 ;i < n ; i++){
            for(int j = i ; j< n ;j++){
                int l = i ,  r = j , x , y;
                if(l==0){
                    x = p_even[r];
                    y = p_odd[r];
                }else{
                    x = p_even[r]-p_even[l-1];
                    y = p_odd[r]-p_odd[l-1];
                }
                if(y==0)continue;
                if( 1LL * q * x <= 1LL* y * p)pairs++;
            }
        }
        return pairs;
    }
};