class Solution {

    int func(int index, int buy, int cap, int n,
             vector<int>& arr,
             vector<vector<vector<int>>>& dp) {

        if (index == n || cap == 0)
            return 0;

        if (dp[index][buy][cap] != -1)
            return dp[index][buy][cap];

        int profit = 0;

        if (buy == 0) {

            profit = max(
                -arr[index] + func(index + 1, 1, cap, n, arr, dp),

                0 + func(index + 1, 0, cap, n, arr, dp)
            );
        }

        if (buy == 1) {

            profit = max(
                arr[index] + func(index + 1, 0, cap - 1, n, arr, dp),

                0 + func(index + 1, 1, cap, n, arr, dp)
            );
        }

        return dp[index][buy][cap] = profit;
    }

public:

    int maxProfit(int k, vector<int>& prices) {

        int n = prices.size();

        if (n == 0)
            return 0;

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(2, vector<int>(k + 1, -1))
        );

        return func(0, 0, k, n, prices, dp);
    }
};