class Solution {
public:
    static bool cmp(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        map<char, int> mpp;
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }
        vector<pair<char, int>> vec;
        for (auto x : mpp) {
            vec.push_back(x);
        }
        sort(vec.begin(), vec.end(), cmp);
        string result = "";
        for (int i = 0; i < vec.size(); i++) {
            string temp(vec[i].second, vec[i].first);
            result += temp;
        }
        return result;
    }
};