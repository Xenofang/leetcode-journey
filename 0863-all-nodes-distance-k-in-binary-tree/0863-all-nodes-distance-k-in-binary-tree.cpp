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
    void  add_in_ans(TreeNode* root ,int k)
    {
        if(root == NULL) return;
        if(k == 0)
        {
            ans.push_back(root->val);
            return;
        }
        add_in_ans(root->left , k-1);
        add_in_ans(root->right , k-1);
    }
    int findT(TreeNode* root, TreeNode* target, int k)
    {
        if(root == NULL) return -1;
        // when find the target
        if(root == target){
            add_in_ans(root , k);
            return 0;
        }
        // if not found 
        int left = findT(root->left , target , k );
        if(left != -1)
        {
            int dist = left+1 ;

            if(dist == k)
            {
                ans.push_back(root->val);
            }
            if(dist < k) 
            {
                add_in_ans(root->right , k-dist-1);
            }
            return dist;
        }
        int right = findT(root->right , target , k);

        if(right != -1)
        {
            int dist = right+1;

            if(dist == k)
            {
                ans.push_back(root->val);
            }
            if(dist < k)
            {
                add_in_ans(root->left , k-1-dist);
            }
            return dist ;
        }
        return -1;
    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        findT(root ,target , k);

        return ans;

    }
};