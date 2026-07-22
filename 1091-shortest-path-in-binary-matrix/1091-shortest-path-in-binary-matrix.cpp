class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        

        if(grid[0][0] == 1) return -1;

        int path = 1;
        q.push({0,0});
        grid[0][0] = 1;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto [r , c] = q.front();
                q.pop();

                int row[] = {-1,1,0,0,-1, -1, 1, 1};
                int col[] =  {0, 0, -1, 1, -1, 1, -1, 1};

                if (r == n-1 && c == n-1)
                return path;

                for(int i = 0 ; i < 8 ; i++)
                {
                    int nr = r + row[i];
                    int nc = c + col[i];

                    if(nr>= 0 && nr < n &&
                        nc >= 0 && nc < n&&
                        grid[nr][nc] == 0)
                    {
                        q.push({nr,nc});
                        grid[nr][nc]= 1;
                    }
                }
            }
            path++;
        }
        return -1;
    }
};