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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        

        queue<TreeNode*> q; 

        if(root == NULL) return{};

        q.push(root);
        int lvl = 0;

        while(!q.empty())
        {
            int size = q.size();
            vector<int>ans;
            
            while(size != 0)
            {
                TreeNode* temp = q.front();
                ans.push_back(temp->val);
                size--;
                q.pop();

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(lvl % 2 != 0)
            {
                reverse(ans.begin() , ans.end());
            }
            lvl+=1;

            result.push_back(ans);

        }
        return result;
    }
};