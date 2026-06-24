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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int,map<int,vector<int>>>m; //for storing all the node data with thier horizontal distance & level,

        queue<pair<TreeNode* , pair<int , int >>>q; //for each node we have hd , lvl , and root

        // to store the data
        vector<vector<int>>result;
        if(root == NULL) return {};

        q.push(make_pair(root , make_pair(0 , 0)));

        while(!q.empty())
        {
            pair<TreeNode* , pair<int , int >> temp  = q.front();

            q.pop();

            TreeNode * frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;

            //store in values in maps 
            m[hd][lvl].push_back(frontNode->val);

            if(frontNode->left)
            {
                q.push(make_pair(frontNode->left , make_pair(hd-1 , lvl+1)));
            }
            if(frontNode->right)
            {
                q.push(make_pair(frontNode->right , make_pair(hd+1 , lvl+1)));
            }

        }

        for(auto HD : m)
        {
            vector<int>ans;
            for(auto LVL : HD.second)
            {
                auto data = LVL.second;
                sort(data.begin() , data.end() );
                for(auto ANS : data)
                {
                    ans.push_back(ANS);
                }
            }
            result.push_back(ans);
        }
        return result;

    }
};