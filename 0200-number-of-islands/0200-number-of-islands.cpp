class Solution {
public:
    //direction arround the land 
    vector<int>dr = {-1,1,0,0};
    vector<int>dc = {0,0,-1,1};

    int numIslands(vector<vector<char>>& grid) {
        // sizes of m & n 
        int m = grid.size();
        int n  = grid[0].size();

        int island = 0 ;

        vector<vector<bool>>vis(m , vector<bool>(n , false));

        // check each cell if its "0" | "1"
        for(int r =  0 ; r < m ; r++)
        {
            for(int c  = 0 ; c < n ; c++)
            {
                // check only for the land 
                if(vis[r][c] == false && grid[r][c] == '1')
                {
                    island++;
                    dfs(r , c , vis , grid);
                }
            }
        }

        return island;

    }

    void dfs(int r , int c  , vector<vector<bool>>& vis ,vector<vector<char>>& grid  )
    {
        int m = grid.size();
        int n  = grid[0].size();
        
        // mark visisted current cell
        vis[r][c] = true;

        for(int i =0 ; i < 4 ; i++)
        {
            // create a  next row and col  for checking next cell

            int nr  = r + dr[i];
            int nc = c + dc[i];

            // check if the conditions  are  matched or not 
            if( nr >= 0  && nr < m && 
            nc >= 0 && nc < n &&  
            grid[nr][nc] == '1' && vis[nr][nc] == false)
            {
                // if condition true means we got another part of the land and merge it with parent land 
                dfs(nr , nc , vis , grid);
            }
        }
    }
};