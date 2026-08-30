class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.length();
        int ans =0;
        unordered_set<char> charset;
        int left =0;

        for ( int right = 0; right < n ; right++) {
            while ( charset.find(s[right])!= charset.end()) {
                charset.erase(s[left]);
                left++;
            }
            charset.insert(s[right]);
            ans= max ( ans , right - left +1);

        }
        return ans;
    }
};