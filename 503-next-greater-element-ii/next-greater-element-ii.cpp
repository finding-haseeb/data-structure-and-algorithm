class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack <int> st;
        vector<int> ans( n , -1);

        for (int i =2* n-1; i >= 0; i--) {
            int index = i %n;
            int currentelement = nums[index];

            while( !st.empty() && st.top() <= currentelement) {
                st.pop();
            }
            if ( i< n ) {
                if( st.empty()) {
                    ans[index] = -1;
                }
                else {
                    ans[index ] = st.top();
                }
            }
            st.push( currentelement );
        }
        return ans;
    }
};