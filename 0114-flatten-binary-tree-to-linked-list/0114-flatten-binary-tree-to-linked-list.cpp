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
    list<TreeNode*> l;
    void solve(TreeNode* root)
    {
        if(root == NULL) return ;

        l.push_back(root);

        solve(root->left);
        solve(root->right);

    }
    void flatten(TreeNode* root) {
        solve(root);
        
        auto curr = l.begin();
        auto next = curr;
        next++;

        while(next != l.end()){
            (*curr)->left = NULL;
            (*curr)->right = *next;
            curr++ ; next++;
        }
        
    }   
};