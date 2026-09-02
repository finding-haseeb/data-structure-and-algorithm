class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1;
        int high = *max_element( piles.begin() , piles.end());
        int ans=0;

        while ( low <= high) {
            int mid = low + ( high - low )/2;
            
            long long sum =0;
            for ( int i =0; i < n ; i++) {
                sum = sum + ((piles[i] -1)/mid) + 1;
            }

            if ( sum <= h) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};