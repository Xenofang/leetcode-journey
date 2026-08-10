class Solution {
public:
    void dfs(int r , int c ,vector<vector<char>>& board )
    {
        int m = board.size();
        int n = board[0].size();
        // base case 
        if( r < 0 || r == m ||
            c < 0 || c == n ||
            board[r][c] != 'O')
            {
                return ;
            }
        board[r][c] = 'T';
        dfs(r-1, c, board); //top
        dfs(r+1, c, board); // bottom
        dfs(r, c-1, board); //left
        dfs(r, c+1, board); //right 
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // for every edges if there is a O  we have  to channge it into temp T
        for(int i= 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if((i == 0 || i == m - 1 || j == 0 || j == n - 1)&& board[i][j] == 'O')
                {
                    dfs(i , j , board);
                }
            }
        }
        // convert all the remaning O into x 
        for(int r = 0 ; r < m ; r++)
        {
            for(int c = 0 ; c < n ; c++)
            {
                if( r >= 0 && r < m &&
                    c >= 0 &&  c < n &&
                    board[r][c] == 'O')
                {
                    board[r][c] = 'X';
                }
                else if(r >= 0 && r < m &&
                    c >= 0 &&  c < n &&
                    board[r][c] == 'T')
                {
                    board[r][c] = 'O';
                }
            }
        }

    }
};