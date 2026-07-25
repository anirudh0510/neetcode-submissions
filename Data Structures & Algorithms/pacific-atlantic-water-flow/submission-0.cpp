class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        queue<pair<int,int>> pacQ;
        queue<pair<int,int>> atlQ;

        // Pacific borders
        for(int i = 0; i < n; i++) {
            pacific[i][0] = 1;
            pacQ.push({i,0});
        }

        for(int j = 0; j < m; j++) {
            pacific[0][j] = 1;
            pacQ.push({0,j});
        }

        // Atlantic borders
        for(int i = 0; i < n; i++) {
            atlantic[i][m-1] = 1;
            atlQ.push({i,m-1});
        }

        for(int j = 0; j < m; j++) {
            atlantic[n-1][j] = 1;
            atlQ.push({n-1,j});
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        // BFS for Pacific
        while(!pacQ.empty()) {

            auto it = pacQ.front();
            pacQ.pop();

            int row = it.first;
            int col = it.second;

            for(int i = 0; i < 4; i++) {

                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   !pacific[nrow][ncol] &&
                   heights[nrow][ncol] >= heights[row][col]) {

                    pacific[nrow][ncol] = 1;
                    pacQ.push({nrow,ncol});
                }
            }
        }

        // BFS for Atlantic
        while(!atlQ.empty()) {

            auto it = atlQ.front();
            atlQ.pop();

            int row = it.first;
            int col = it.second;

            for(int i = 0; i < 4; i++) {

                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   !atlantic[nrow][ncol] &&
                   heights[nrow][ncol] >= heights[row][col]) {

                    atlantic[nrow][ncol] = 1;
                    atlQ.push({nrow,ncol});
                }
            }
        }

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};