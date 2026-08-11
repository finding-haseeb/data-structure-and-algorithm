class Solution {
    int LCS(string &s, string&reverse_string, int m, int n) {
		
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		
		for (int i = 1 ; i < m + 1 ; i++) {
			for (int j = 1 ; j < n + 1 ; j++) {
				if (s[i - 1] == reverse_string[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				}
				else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			}
		}
		return dp[m][n];
	}
public:
    int minInsertions(string s) {
        string reverse_string = s;
		reverse(reverse_string.begin(), reverse_string.end());
		
		int n = s.length();
		return n - LCS(s, reverse_string, n, n);
    }
};


