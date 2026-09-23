class Solution {
    static bool comp(const vector<int>& val1, const vector<int>& val2) {
        return val1[1] < val2[1];
    }

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if (n == 0)
            return 0;

        sort(intervals.begin(), intervals.end(), comp);

        int count = 1;
        int lastendtime = intervals[0][1];

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= lastendtime) {
                count++;
                lastendtime = intervals[i][1];
            }
        }

        return n - count;
    }
};