class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = - 1 , u = -1;

        int i  = 0 , j = nums.size()-1;

        // lower
        while(i <= j)
        {
            int mid = i +(j-i)/2;

            if(nums[mid] == target)
            {
                l = mid;
                j = mid -1;
            }
            else if(nums[mid] < target) i = mid+1 ;
            else j = mid-1;
        }
        i  = 0 , j = nums.size()-1;
        // upper

        while(i <= j)
        {
            int mid = i +(j-i)/2;

            if(nums[mid] == target)
            {
                u = mid;
                i = mid +1 ;
            }
            else if(nums[mid] < target) i = mid +1;
            else j = mid -1;
        }

        return {l , u};

    }
};