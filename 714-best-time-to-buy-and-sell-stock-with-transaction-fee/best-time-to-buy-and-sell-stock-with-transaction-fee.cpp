class Solution {
    int func(int index, int buy, int fee, int n, vector<int>& arr,
             vector<vector<int>>& dp) {
        if (index == n)
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];
        int profit = 0;

        if (buy == 0) {
            profit = max(-arr[index] + func(index + 1, 1, fee, n, arr, dp),
                         0 + func(index + 1, 0, fee, n, arr, dp));
        }
        if (buy == 1) {
            profit = max(arr[index] - fee + func(index + 1, 0, fee, n, arr, dp),
                         0 + func(index + 1, 1, fee, n, arr, dp));
        }
        return dp[index][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        if (n == 0)
            return 0;

        vector<vector<int>> dp(n, vector<int>(2, -1));
        return func(0, 0, fee, n, prices, dp);
    }
};