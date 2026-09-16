class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maximumreach =0;

        for ( int i =0; i < nums.size(); i++) {
            if( i >maximumreach) {
                return false;
            }

            maximumreach = max( maximumreach , i + nums[i]);
        }
        return true;
        
    }
};