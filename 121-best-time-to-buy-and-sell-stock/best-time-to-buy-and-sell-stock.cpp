class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxprofit = 0;

        int left = 0;
        int right = 1;

        while (right < n) {
            if (prices[left] > prices[right]) {
                left= right;
            }
            else if ( prices[left] < prices[right]) {
                int profit = prices[right]- prices[left];
                maxprofit = max( maxprofit , profit);
            }
            right++;
        }
        return maxprofit;
    }
};