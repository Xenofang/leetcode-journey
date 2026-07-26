class Solution {
public:
    void solve(vector<int>& nums ,vector<int>& ans , int i ,  vector<vector<int>>& allSubset)
    {
        if(i== nums.size())
        {
            allSubset.push_back(ans);
            return;
        }
        // include
        ans.push_back(nums[i]);
        solve(nums , ans, i+1 , allSubset);

        // backtracking and removing after came back from the base case.
        ans.pop_back();

        // exclusion
        solve(nums , ans , i+1 , allSubset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>>allSubset;
        solve(nums, ans , 0 , allSubset);
        return allSubset;
    }
};