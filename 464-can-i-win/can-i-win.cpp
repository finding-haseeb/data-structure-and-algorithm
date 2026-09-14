class Solution {
public:
    unordered_map<int, bool> dp;

    bool solve(int mask, int target, int maxChoosableInteger) {
        if (dp.count(mask))
            return dp[mask];

        for (int i = 1; i <= maxChoosableInteger; i++) {
            int bit = 1 << (i - 1);

            if (!(mask & bit)) {
                if (i >= target || !solve(mask | bit, target - i, maxChoosableInteger)) {
                    return dp[mask] = true;
                }
            }
        }

        return dp[mask] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal <= 0)
            return true;

        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;

        if (sum < desiredTotal)
            return false;

        return solve(0, desiredTotal, maxChoosableInteger);
    }
};