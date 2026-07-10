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
    TreeNode* getIs(TreeNode* root)
    {
        while(root!= NULL && root->left != NULL)
        {
            root= root->left; 
        }
        return root ;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        // Find the key val 
        if(root->val > key)  root->left = deleteNode(root->left ,key);
        else if(root->val < key) root->right  = deleteNode(root->right ,key);

        // when root & key val are matched 
        else{
            // handle 0 , 1
            if(root->left == NULL)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if( root->right == NULL)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // handle 2 is !NULL
            if(root->left != NULL && root->right != NULL)
            {
                TreeNode* iS = getIs(root->right);
                root->val = iS->val;
                root->right = deleteNode(root->right , iS->val);
               
            }

        }
        return root;
    }
};