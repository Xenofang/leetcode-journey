class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0 ,j = nums.size()-1;

        while(i <= j)
        {
            int mid = i +(j - i) / 2;

            if(nums[mid]== target) return mid;

            // check which side is sorted 
                // if left side
            if(nums[i] <= nums[mid]){
                // check if this l s have the target value
                if(nums[i] <= target && target <= nums[mid]) j = mid-1;
                else i= mid+1;
            }
            // for right side  is sorted
            else{
                if(nums[mid] <= target && target <= nums[j]) i = mid+1;
                else j = mid -1;
            }

        }
        return -1;
    }
};