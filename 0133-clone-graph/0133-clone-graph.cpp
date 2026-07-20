/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node == NULL)  return NULL;

        
        queue<Node*>q;

        unordered_map<Node* , Node*> mp;

        mp[node] = new Node ( node->val);

        q.push(node);

        while(!q.empty()){
            Node* curr = q.front();
            q.pop();

            for(auto nbr : curr->neighbors)
            {
                // if there is no  clone in map  then  make a clone 
                if(mp.find(nbr) == mp.end()) 
                {
                    mp[nbr] = new Node (nbr->val);
                    q.push(nbr);

                }
                mp[curr]->neighbors.push_back(mp[nbr]);
            }
        }

        return mp[node];
    }
};