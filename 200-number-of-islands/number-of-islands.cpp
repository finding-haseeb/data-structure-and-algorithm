class Solution {
    void bfs(int row, int column, vector<vector<int>>& visited, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        visited[row][column] = 1;
        queue<pair<int, int>> q;
        q.push({row, column});

        int delrow[] = {-1, 0, 1, 0};
        int delcolumn[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncolumn = c + delcolumn[i];

                if (nrow >= 0 && nrow < n && ncolumn >= 0 && ncolumn < m && 
                    grid[nrow][ncolumn] == '1' && visited[nrow][ncolumn]!=1) {
                    
                    visited[nrow][ncolumn] = 1;
                    q.push({nrow, ncolumn});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;

        for (int row = 0; row < n; row++) {
            for (int column = 0; column < m; column++) {
                if (grid[row][column] == '1' && !visited[row][column]) {
                    count++;
                    bfs(row, column, visited, grid);
                }
            }
        }

        return count;
    }
};