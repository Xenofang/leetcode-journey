class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<int> q;
        vector<bool>vis(n,false);
        vector<vector<int>>adj(n);

        for (auto edge : edges)
        {
            // in edges only two element connection 
            int u = edge[0];
            int v = edge[1];

           
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if(source == destination ) return true;
        q.push(source);
        vis[source] = true;
        while(!q.empty())
        {
            int s = q.front();
            q.pop();

            for(int d : adj[s])
            {
                if(vis[d] == false)
                {
                    vis[d] = true;
                    if(d == destination) return true;
                    q.push(d);
                }
            }
        }
        return false;
    }
};