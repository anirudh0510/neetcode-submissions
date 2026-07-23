class Solution {
public: 
    void bfs(int row , int col  , int n , int m , vector<vector<int>>&grid , vector<vector<int>>&vis, int &maxarea){

        vis[row][col]=1;
        int area=1;
        maxarea = max(maxarea, area);
        queue<pair<int,int>>q;
        q.push({row , col});

        int delrow[]={-1 , 0 , 1 , 0};
        int delcol[]={0 , 1 , 0 , -1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0 ; i<4 ; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if(nrow >= 0 && ncol >=0 && nrow <n && ncol <m && grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    area++;
                    maxarea=max(maxarea , area);
                    vis[nrow][ncol]=1;
                    q.push({nrow , ncol});
                }
            }
        }


    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>vis (n,vector<int>(m,0));
        int maxarea=0;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    bfs(i , j , n , m , grid , vis , maxarea);
                }
            }
        }
        return maxarea;

    }
};