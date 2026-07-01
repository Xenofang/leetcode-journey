/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>ans;

    void solve(TreeNode* root , int k)
    {
        if(root == NULL) return ;

        if(k==0)
        {
            ans.push_back(root->val);
            return;
        }
        solve(root->left , k-1);
        solve(root->right , k-1);

    }
    int findT(TreeNode* root, TreeNode* target, int k)
    {
        if(root == NULL) return -1 ;

        if(root == target)
        {
            solve(target , k);
            return 0;
        }
        int left = findT(root->left , target , k);

        if(left != -1)
        {
            int dist = left+1 ;

            if(dist == k) {
                ans.push_back(root->val);
            }
            if(dist < k)
            {
                solve(root->right , k-dist-1);
            }

            return dist;
        }

        int right = findT(root->right , target , k);

        if(right != -1 )
        {
            int dist = right+1 ;

            if(dist == k) 
            {
                ans.push_back(root->val);
            }
            if(dist < k)
            {
                solve(root->left , k - dist - 1);
            }
            return dist;
        }

        return -1;


    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         findT(root , target , k);

        return ans;
    }
};