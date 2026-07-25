class Solution {
public:
    void dfs(int row, int col, int n, int m,
             vector<vector<char>>& board,
             vector<vector<int>>& vis) {

        vis[row][col] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && ncol >= 0 &&
               nrow < n && ncol < m &&
               !vis[nrow][ncol] &&
               board[nrow][ncol] == 'O') {

                dfs(nrow, ncol, n, m, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Start DFS from all boundary O's
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if((i == 0 || i == n - 1 || j == 0 || j == m - 1) &&
                   board[i][j] == 'O' &&
                   !vis[i][j]) {

                    dfs(i, j, n, m, board, vis);
                }
            }
        }

        // Convert surrounded O's to X
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};