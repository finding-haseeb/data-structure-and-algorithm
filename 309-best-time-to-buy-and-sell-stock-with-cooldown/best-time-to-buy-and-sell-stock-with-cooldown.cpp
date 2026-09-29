class Solution {
    int func(int index, int buy, int n,
             vector<int>& arr,
             vector<vector<int>>& dp) {

        if (index >= n)
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;

        if (buy == 0) {

            // Buy
            profit = max(
                -arr[index] + func(index + 1, 1, n, arr, dp),

                // Don't buy
                func(index + 1, 0, n, arr, dp)
            );
        }

        else {

            // Sell + cooldown
            profit = max(
                arr[index] + func(index + 2, 0, n, arr, dp),

                // Don't sell
                func(index + 1, 1, n, arr, dp)
            );
        }

        return dp[index][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        if (n == 0)
            return 0;

        vector<vector<int>> dp(
            n,
            vector<int>(2, -1)
        );

        return func(0, 0, n, prices, dp);
    }
};