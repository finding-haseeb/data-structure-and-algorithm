class Solution {
    
    void dfs(vector<vector<int>>& image, int sr, int sc,
             int initialcolor, int color,
             vector<vector<int>>& ans) {
        
        int n = image.size();
        int m = image[0].size();

        // Change current cell
        ans[sr][sc] = color;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                image[nrow][ncol] == initialcolor &&
                ans[nrow][ncol] != color) {
                
                dfs(image, nrow, ncol,
                    initialcolor, color, ans);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {
       
        int initialcolor = image[sr][sc];

        vector<vector<int>> ans = image;

        dfs(image, sr, sc, initialcolor, color, ans);

        return ans;
    }
};