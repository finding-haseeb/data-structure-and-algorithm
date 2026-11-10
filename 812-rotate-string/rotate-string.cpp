class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        string dummy = s + s;
        if (dummy.find(goal) != string::npos) {
            return true;
        }
        return false;
    }
};