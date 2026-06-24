class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int l = 0 , r = n-1 ;
        int maxwater = 0;

        while(l < r)
        {
            int ht = min(height[l] , height[r]);
            int w = r-l;
            int area =  ht * w;

            maxwater = max(area , maxwater);

            if(height[l] < height[r] ) l++;
            else r--;

        }
        return maxwater;
    }
};