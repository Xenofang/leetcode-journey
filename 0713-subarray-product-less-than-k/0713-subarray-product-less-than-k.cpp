class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int prod = 1 , count = 0;
         int i =0 , j=i;
        while(j<nums.size() )
        {
            prod *= nums[j];
           
            while(prod >= k ){
               prod /=nums[i];
               i++;
            }
            count+= j-i+1;
            j++;
            
                
            
        }
        return count ;
    }
};