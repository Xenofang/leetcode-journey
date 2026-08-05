class Solution {
public:
    void dfs( int  s ,vector<int>& vis ,vector<vector<int>>& isConnected  )
    {
        int n = isConnected.size();
        vis[s] = true;

        for(auto j = 0 ; j < n ; j++)
        {
            if(isConnected[s][j] == 1 && vis[j] == false)
            {
                dfs( j , vis ,isConnected );
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {

       int count = 0 ;
       int n = isConnected.size();

       vector<int>vis (n,false);

       for(int i = 0 ; i < n ; i++ )
       {
            if(vis[i] == false)
            {
                count++;
                dfs(i , vis , isConnected);
            }
       }

       return count;
   
    }
};