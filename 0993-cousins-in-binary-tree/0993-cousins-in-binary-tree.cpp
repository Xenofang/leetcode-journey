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
    TreeNode* parent = NULL ;
    int  depth = 0;
    TreeNode* parentX = NULL ;
    int  depthX = 0;
    TreeNode* parentY = NULL ;
    int  depthY = 0;

    void solve(TreeNode* root , TreeNode* parent , int depth , int& x , int& y)
    {
        if(root == NULL) return;

        if(root->val == x ) {
            parentX = parent;
            depthX = depth;
            return;
        }
        if(root->val == y ) {
            parentY = parent;
            depthY = depth;
            return;
        }

        //left 
        solve(root->left , root , depth+1 , x , y);
        //right
        solve(root->right , root , depth+1 , x , y);

        
    }


    bool isCousins(TreeNode* root, int x, int y) {
        
        if(root == NULL ) return false;

        solve(root , parent , depth , x , y);

        return (parentX != parentY && depthX == depthY);
    }
};