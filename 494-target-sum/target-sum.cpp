class Solution {
    int countsubsetsum(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (i == 0)
                    dp[i][j] = 0;
                if (j == 0)
                    dp[i][j] = 1;
            }
        }
        
        for ( int i =1; i < n +1 ; i++) {
             // Handle zero
            if (nums[i - 1] == 0)
                dp[i][0] = 2 * dp[i - 1][0];
            else
                dp[i][0] = dp[i - 1][0];
            for ( int j =1 ; j< sum+1 ; j++) {
                if ( nums[i-1] <= j ) {
                    dp[i][j] = dp[i-1][j- nums[i-1]] + dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
        }

        if (abs(target) > sum)
            return 0;

        if ((sum + target) % 2 != 0)
            return 0;

        int s1 = (sum + target) / 2;

        return countsubsetsum(nums, s1);
    }
};