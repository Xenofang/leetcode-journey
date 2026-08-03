class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // cycle detection question

        // make adj list 
        int n = graph.size();

        vector<bool>vis(n , false);
        vector<bool>rPath(n , false);

        for(int node = 0 ; node < n ; node++)
        {
            if(vis[node] == false)
            {
                dfs(node , vis , rPath , graph);
            }
        }
        vector<int>ans;
        for(int j = 0 ; j <  rPath.size() ; j++ )
        {
            if(rPath[j] == false) ans.push_back(j);
        }
        return ans ;
    }

    bool dfs(int s ,vector<bool>& vis , vector<bool>& rPath , vector<vector<int>>& graph)
    {
        vis[s] = true;
        rPath[s] = true;

        for(int neigh :  graph[s])
        {
            if(vis[neigh] == false && rPath[neigh] == false)
            {
                if(dfs(neigh , vis , rPath , graph)) return true;
            }
            else if (rPath[neigh] == true)
            {
                return true ; // found the cycle 
            }
        }
        rPath[s] = false;

        return false;

    }

};