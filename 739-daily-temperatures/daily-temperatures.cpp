class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        
        stack<pair<int, int>> st;
        vector<int> output(n, 0);

        for(int i = n - 1; i >= 0; i--) {
            
            // current temperature se chote/equal ko pop karo
            while(!st.empty() && temperatures[i] >= st.top().first) {
                st.pop();
            }
            
            // agar stack empty nahi hai
            if(!st.empty()) {
                output[i] = st.top().second - i;
            }

            st.push({temperatures[i], i});
        }

        return output;
    }
};