class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        // dp[i] = minimum coins needed for amount i
        vector<int> dp(amount + 1, amount + 1);
        
        // Base case
        dp[0] = 0;
        
        // Fill dp array
        for(int i = 1; i <= amount; i++) {
            for(int coin : coins) {
                if(i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        // If not possible
        if(dp[amount] > amount)
            return -1;
        
        return dp[amount];
    }
};
