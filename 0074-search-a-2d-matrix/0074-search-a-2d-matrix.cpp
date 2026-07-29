class Solution {
public:
    // we can also use binary search 
    bool isfound(vector<vector<int>>& mat, int m , int n , int midR ,int target)
    {
        int i = 0 , j = n-1 ;
        while(i <= j)
        {
            int mid = i + (j-i)/2;

            if(mat[midR][mid] == target)return true;

            if(mat[midR][mid] < target) i = mid+1;
            else j = mid -1 ;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        int stR = 0 , endR = m-1;

        while(stR <= endR)
        {
            int midR = stR+(endR - stR)/2;

            if(mat[midR][0] <= target && target <= mat[midR][n-1])
            {
                return isfound(mat ,m , n ,midR ,target);
            }
            if(target > mat[midR][n-1])
            {
                stR = midR+1;
            }
            else endR = midR-1;
        }
        return false;
    }
};