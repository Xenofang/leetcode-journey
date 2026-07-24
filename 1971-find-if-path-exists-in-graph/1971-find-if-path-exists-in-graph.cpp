class Solution {
public:
    bool dfs( vector<vector<int>>&adj , vector<bool>&vis , int src , int destination ){
        if(src == destination) return true;
        else{
            vis[src] = true;

            for(int i : adj[src])
            {
                if(vis[i] == false)
                {
                    if( dfs(adj , vis , i , destination )) return true;
                }
            }
        }
        return false;

    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        vector<bool>vis(n,false);

        for(auto i : edges)
        {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        return dfs(adj , vis , source , destination);
    }
};