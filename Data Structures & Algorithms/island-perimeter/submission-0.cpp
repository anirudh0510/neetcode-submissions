class Solution {
public:
    void solve(vector<vector<int>>& grid, int i, int j, int &perimeter) {

        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            perimeter++;
            return;
        }

        if (grid[i][j] == -1)
            return;

        grid[i][j] = -1;

        solve(grid, i + 1, j, perimeter);
        solve(grid, i - 1, j, perimeter);
        solve(grid, i, j + 1, perimeter);
        solve(grid, i, j - 1, perimeter);
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int perimeter = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {
                    solve(grid, i, j, perimeter);
                    return perimeter;
                }
            }
        }

        return 0;
    }
};