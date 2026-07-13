class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0 , ans = INT_MIN;

        for(int i : nums)
        {
            sum+=i;

            ans = max(sum , ans );

            if(sum < 0) sum = 0;

        }
        return ans;
    }
};