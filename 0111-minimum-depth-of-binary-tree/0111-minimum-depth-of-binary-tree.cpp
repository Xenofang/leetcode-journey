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
    int minNodes(TreeNode* root)
    {
        if(root == NULL) return 0 ;
        if(root->left == NULL && root->right == NULL) return 1;

        int left = minNodes(root->left);
        int right = minNodes(root->right);

        if(left == 0) return right+1;
        else if(right == 0) return left+1 ;
        return min(left , right) +1;
    }
    int minDepth(TreeNode* root) {
        int ans = minNodes(root);
        return ans;
    }
};