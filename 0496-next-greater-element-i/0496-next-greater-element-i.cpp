class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        vector<int>ans(nums1.size());
        unordered_map<int,int>m;
// 1. find nums2 Next greater element.
        for(int i = nums2.size()-1 ; i >=0 ; i-- )
        {
            while(!s.empty() && nums2[i] >=s.top())
            {
                s.pop();
            }
            if(s.empty()) m[nums2[i]] = -1;
            else{
                m[nums2[i]] = s.top();
            }
            s.push(nums2[i]);
        }
// 2. paste the value form map to ans 
        for(int j = nums1.size()-1 ; j >= 0 ; j--)
        {
            ans[j] = m[nums1[j]];
        }
        return ans;
    }
};