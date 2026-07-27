class Solution {
public:
    int dr[4] = {-1 , 1 , 0 , 0 };
    int dc[4] = { 0 , 0 , -1 , 1 };

    void dfs( int r , int c ,vector<vector<char>>& grid , vector<vector<bool>>&vis )
    {
        int m = grid.size();
        int n = grid[0].size();

        vis[r][c] = true;

        for(int i = 0 ; i < 4 ; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >=0 && nr < m &&
                nc >= 0 && nc < n &&
                grid[nr][nc] == '1' && vis[nr][nc] == false)
            {
                dfs(nr, nc , grid , vis);
            }
        }


    }

    int numIslands(vector<vector<char>>& grid) {

        // size of grid 
        int m = grid.size();
        int n = grid[0].size();

        int count = 0 ;

        // visited 
        vector<vector<bool>>vis(m , vector<bool>(n , false));

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j< n ;j++)
            {
                // if island found 
                if(grid[i][j] == '1' && vis[i][j]== false)
                {
                    count++;
                    dfs(i , j , grid , vis); 
                }

            }
        }
        return count ;
    }
};