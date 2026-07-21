class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1 ;
        int element = nums[0];

        for(int i = 1 ; i < n ;i++)
        {
            if(count == 0)
            {
                element = nums[i];
            }
            if(element == nums[i])
            {
                count++;
            }
            else count--;
        }
        return element ;
    }
};