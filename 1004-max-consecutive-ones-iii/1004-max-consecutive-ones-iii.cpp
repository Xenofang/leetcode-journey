class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l =0 ;
        int maxlen =0 ;
        int c0 = 0;

        for(int r = 0 ; r<nums.size(); r++)
        {
            if(nums[r] == 0)
            {
                c0++;
            }

            if(c0 > k)
            {
                if(nums[l] == 0)
                {
                    c0--;
                }
                l++;
            }
        }
        return nums.size()- l;
    }
};