class Solution {
    int func( int index , int buy , int n , vector<int>& prices , vector<vector<int>>& dp) {
        if ( index ==n ) {
            return 0;
        }

        if ( dp[index][buy] !=-1) {
            return dp[index][buy];
        }

        int profit =0;

        if ( buy==0) {
            profit = max( (-1) * prices[index] + func( index +1 , 1, n ,prices, dp ),
                            0 + func(index+1 , 0 , n , prices, dp));
        }
        if ( buy ==1) {
            profit = max ( prices[index] + func( index +1 , 0 , n, prices, dp ),
                            0 + func( index +1 , 1 , n , prices, dp ));
        }
        return dp[index][buy]= profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if ( n==0) return 0;

        vector<vector<int>> dp ( n , vector<int>( 2 , -1));
        
        return func( 0  , 0 , n , prices , dp );
        
    }
};