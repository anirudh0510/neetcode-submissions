class Solution {
public:

    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        q.push({row, col});
        vis[row][col] = 1;

        // up, right, down, left
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {

                int nr = r + delRow[i];
                int nc = c + delCol[i];

                // valid cell + land + not visited
                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   grid[nr][nc] == '1' &&
                   !vis[nr][nc]) {

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int count = 0;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                if(grid[i][j] == '1' && !vis[i][j]) {

                    count++;

                    bfs(i, j, grid, vis);
                }
            }
        }

        return count;
    }
};