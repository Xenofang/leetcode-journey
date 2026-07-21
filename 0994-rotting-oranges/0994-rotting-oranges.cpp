class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();


        queue<pair<int,int>>q;
        int fresh = 0 ;



        for(int i = 0 ; i < m ;i++)
        {
            for(int j = 0 ; j < n ; j++ )
            {
                if( grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0 ) return 0;

        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};

        int minitues = -1;

        while(!q.empty())
        {
            int size = q.size();

            while(size > 0)
            {
                auto [r,c] = q.front();
                q.pop();
                size--;
                for(int i = 0 ; i < 4 ; i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if( nr >= 0 && nr < m && 
                        nc >= 0 && nc < n && 
                        grid[nr][nc] == 1 )
                    {
                        grid[nr][nc] = 2 ;
                        q.push({nr , nc});
                        fresh--;
                    }
                }
            }
            minitues++;
        }

        return (fresh == 0 )? minitues :-1;
    }
};