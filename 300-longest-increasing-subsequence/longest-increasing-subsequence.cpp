class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for (int index = n-1; index >= 0; index--) {
            for (int previndex = index-1; previndex >= -1; previndex--) {

                // not take
                int nottake = dp[index+1][previndex+1];

                // take
                int take = 0;

                if (previndex == -1 || nums[index] > nums[previndex]) {
                    take = 1 + dp[index+1][index+1];
                }

                dp[index][previndex+1] = max(take, nottake);
            }
        }

        return dp[0][0];
    }
};