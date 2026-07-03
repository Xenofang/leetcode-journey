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
    vector<TreeNode*> vec;
    void solve(TreeNode* root)
    {
        if(root == NULL) return ;

        vec.push_back(root);

        solve(root->left);
        solve(root->right);

    }
    void flatten(TreeNode* root) {
        solve(root);
        if(vec.empty()) return;
        for(int i = 0 ; i < vec.size()-1 ; i++ )
        {
            vec[i]->left = NULL;
            vec[i]->right = vec[i+1];
        }
        // only connects last second 

        vec.back()->right = NULL;
        vec.back()->left = NULL;
    
        
    }   
};