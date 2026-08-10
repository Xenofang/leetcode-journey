class Solution {
public:
    bool dfs(int s , vector<bool> &vis , vector<bool>& rPath ,vector<vector<int>>& adj )
    {
        vis[s] = true;
        rPath[s] = true;

        for(int neigh : adj[s])
        {
            if(vis[neigh] == false)
            {
                if(dfs(neigh ,vis , rPath, adj)) return true;
            }
            else if(rPath[neigh] == true)
            {
                return true;
            }
        }
        rPath[s] = false;

        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        // cycle or not 
        // adj list
        vector<vector<int>>adj(n);
        for(auto i : edges )
        {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
        }
        

        vector<bool> vis(n ,false);
        vector<bool> rPath(n ,false);


        for(int i = 0 ; i < n ;i++)
        {
            if(vis[i] == false)
            {
                if(dfs( i , vis , rPath , adj )) return  false; //cycle decteted so false;
            }
        }

        return true;


    }
};