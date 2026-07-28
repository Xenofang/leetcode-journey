class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // size
        int m = grid.size();
        int n = grid[0].size();

        // storing rotten oranges
        queue<pair<int,int>> q;

        // storing the quantity of fresh oranges 
        int fresh =0 ;
        
        // minutes to rotten all oranges 
        int min = -1;

        // check all the cells how many rotten and fresh oranges
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(grid[i][j] == 2 ) q.push({i,j});
                else if(grid[i][j] == 1) fresh++; 
            }
        }

        if(fresh == 0 ) return 0;

        // adjecent direction 
        int dr[4] = {-1,1 , 0 ,0};
        int dc[4] = {0,0,-1,1};

        while(!q.empty())
        {
            int size = q.size();
            while(size > 0)
            {
                // queue starting  cell
                auto [r,c] = q.front();
                q.pop();
                size--;
                // check all the adj direction
                for(int i = 0 ; i < 4 ; i++)
                {
                    // check for next row and col 
                    int nr  = r+dr[i];
                    int nc = c+dc[i];
                    
                    // validate next row and col with  condition 
                    if(nr >= 0  && nr < m &&
                        nc >= 0 && nc < n && 
                        grid[nr][nc] == 1)
                    {
                        fresh--;
                        grid[nr][nc] = 2 ;
                        q.push({nr ,nc});
                    }
                }
            }
            min++;
        }
        return (fresh > 0 ) ? -1 : min;
    }
};