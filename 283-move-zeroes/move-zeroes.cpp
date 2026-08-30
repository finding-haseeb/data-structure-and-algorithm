class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertindex =0;

        for( int i=0; i < nums.size() ; i++) {
            if( nums[i]!= 0) {
                nums[insertindex] =nums[i];
                insertindex++;
            }
        }

        for(int i =insertindex ; i < nums.size() ; i++) {
            nums[i] = 0;
        }

        
    }
};