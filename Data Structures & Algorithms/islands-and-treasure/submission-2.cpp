class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n , vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0 ; i<n ;i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j]==0){
                    q.push({i , j});
                    vis[i][j]=1;
                }
            }
        }
        int delrow[]={-1 , 0 , 1 , 0};
        int delcol[]={0 , 1 , 0 , -1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0 ; i <4 ; i++){
                int nrow=row + delrow[i];
                int ncol=col + delcol[i];

                if(nrow >=0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == INT_MAX && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    grid[nrow][ncol]=grid[row][col]+1;
                    q.push({nrow , ncol});
                }
            }
        }

    }
};
