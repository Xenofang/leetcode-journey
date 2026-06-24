class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        
        for(int j =i ; j<n ; j++)
        {
            
                if(nums[j] != 0)
                {
                    swap(nums[i] , nums[j]);
                    i++;
                }
        }
    }
};