class Solution {
public:
    bool dfs(vector<vector<char>>& board, int row, int col, int index, string &word) {

        if (index == word.size())
            return true;

        int n = board.size();
        int m = board[0].size();

        if (row < 0 || col < 0 || row >= n || col >= m ||
            board[row][col] != word[index])
            return false;

        char ch = board[row][col];
        board[row][col] = '#';

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (dfs(board, nrow, ncol, index + 1, word)) {
                board[row][col] = ch;
                return true;
            }
        }

        board[row][col] = ch;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == word[0] &&
                    dfs(board, i, j, 0, word))
                    return true;
            }
        }

        return false;
    }
};