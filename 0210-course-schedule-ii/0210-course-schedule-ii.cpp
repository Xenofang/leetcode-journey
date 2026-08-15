class Solution {
public:
    bool dfs(int s , vector<int>& vis ,  vector<int>& rPath ,vector<vector<int>>& adj , stack<int>& st)
    {
        vis[s] = true ;
        rPath[s] = true;
        
        for(int neigh : adj[s])
        {
            if(vis[neigh] == false)
            {
                if(dfs(neigh , vis, rPath,adj, st)) return true;
            }
            else if(rPath[neigh] == true)
            {
                return true;
            }
        }
        rPath[s] = false;
        st.push(s);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto i : edges)
        {
            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);

        }
        vector<int>vis(n,false);
        vector<int>rPath(n,false);

        stack<int>st;

        for(int i = 0 ; i < n ; i++)
        {
            if(vis[i] == false)
            {
                if(dfs(i , vis ,rPath , adj ,st))
                return{};
            }

        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());

            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans ;

    }
};