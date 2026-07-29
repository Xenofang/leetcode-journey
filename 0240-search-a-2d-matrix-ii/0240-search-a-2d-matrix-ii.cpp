class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size() , n = mat[0].size();

        int r = 0 , c = n-1;

        while(r <= m-1 && c >= 0)
        {
            if(target == mat[r][c]) return true;

            if(mat[r][c] > target) c--;
            else r++;
        } 
        return false;
    }
};