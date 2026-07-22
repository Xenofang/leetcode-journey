class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // check if  the 00 is 1 then  direcrt return 
        if(grid[0][0] == 1 ) return -1;
        
        // make a queue for storing ans 
        queue<pair<int,int>>q;
        // count the sortest  path as follows the level by level
        int path = 1;

        q.push({0,0});
        
        // 8 direction 
        int row[] = {-1,1,0,0,-1,-1,1,1};
        int col[] = {0,0,-1,1,-1,1,-1,1};

        while(!q.empty())
        {
            int size = q.size();

            while(size > 0  ) 
            {
                auto [r,c] = q.front();
                q.pop();
                size--;
                
                if(r== n-1 && c == n-1) return path;

                for(int i = 0 ; i < 8 ; i++)
                {
                    int nr = r + row[i];
                    int nc = c+ col[i];

                    if(nr >= 0 && nr < n &&
                        nc >= 0 && nc < n && 
                        grid[nr][nc]== 0 )
                    {
                        q.push({nr,nc});
                        grid[nr][nc] = 1;
                    }
                    
                }
            }
            path++;
        }

        return-1;
    }
};