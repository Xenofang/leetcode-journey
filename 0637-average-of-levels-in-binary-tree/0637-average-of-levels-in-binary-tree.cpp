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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty())
        {

            
            long long size = q.size(), n = size;
            long long  sum = 0;
            while(size != 0 )
            {
                TreeNode* temp = q.front();
                q.pop();
                sum+=temp->val;
                size--;

                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }

            }
            double avg = (double)sum/n;
            ans.push_back(avg);
        }
        return ans;
    }
};