class Solution {
public:
    vector<vector<int>> ans;
    vector<int>path;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int source = 0 ;
        int target = graph.size()-1;

        dfs(source , target , graph);

        return ans;
    }

    void dfs(int curr , int target ,vector<vector<int>>& graph )
    {
        path.push_back(curr);

        if(curr == target)
        {
            ans.push_back(path);
            path.pop_back();
            return;
        }

        for(int neigh : graph[curr])
        {
            dfs(neigh , target , graph);
        }

        path.pop_back();

        return;
    }
};