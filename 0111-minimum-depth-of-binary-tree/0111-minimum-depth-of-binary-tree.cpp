/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root){
        if(root == NULL ) return 0 ;
        if(root->left == NULL && root->right == NULL) return 1;

        int left = solve(root->left);
        int right = solve(root->right);

        if(left == NULL) return right+1;
        else if(right == NULL) return left+1;

        return min(left , right)+1;
    }

    int minDepth(TreeNode* root) {
        int ans = solve(root);
        return ans;
    }
};