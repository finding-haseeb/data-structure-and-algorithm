class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int m = s.length();

        string aulta = s;
        reverse(aulta.begin(), aulta.end());

        int n = aulta.length();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {

                if (s[i - 1] == aulta[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }
};