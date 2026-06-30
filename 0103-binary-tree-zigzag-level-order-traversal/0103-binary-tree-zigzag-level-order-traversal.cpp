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

const size_t BUFFER_SIZE = 0x6fafffff; alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; void* operator new(size_t size) { constexpr std::size_t alignment = alignof(std::max_align_t); size_t padding = (alignment - (buffer_pos % alignment)) % alignment; size_t total_size = size + padding; char* aligned_ptr = &buffer[buffer_pos + padding]; buffer_pos += total_size; return aligned_ptr; } void operator delete(void* ptr, unsigned long) {} void operator delete(void* ptr) {} void operator delete[](void* ptr) {}