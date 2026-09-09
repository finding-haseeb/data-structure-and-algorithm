class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();

        vector<vector<int>> visited(row, vector<int>(col, 0));
        queue<pair<pair<int, int>, int>> q;
        // Put all rotten oranges into queue
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
            }
        }
        int time = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        // BFS
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            for (int i = 0; i < 4; i++) {

                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if (nrow >= 0 && nrow < row && ncol >= 0 && ncol < col &&
                    grid[nrow][ncol] == 1 && visited[nrow][ncol] == 0) {
                    q.push({{nrow, ncol}, t + 1});
                    visited[nrow][ncol] = 2;
                }
            }
        }
        // Check remaining fresh oranges
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && visited[i][j] != 2) {
                    return -1;
                }
            }
        }
        return time;
    }
};