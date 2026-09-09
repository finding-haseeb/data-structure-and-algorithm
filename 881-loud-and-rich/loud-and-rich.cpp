class Solution {
public:
    vector<vector<int>> adj;
    vector<int> quiet;
    vector<int> ans;

    int dfs(int person) {

        if (ans[person] != -1) {
            return ans[person];
        }

        // Initially, the quietest person is the person itself
        ans[person] = person;

        for (int richerPerson : adj[person]) {

            int candidate = dfs(richerPerson);

            if (quiet[candidate] < quiet[ans[person]]) {
                ans[person] = candidate;
            }
        }

        return ans[person];
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {

        int n = quiet.size();

        adj.resize(n);
        this->quiet = quiet;
        ans.assign(n, -1);

        // richerPerson -> poorerPerson
        // Store richer people for every person
        for (auto& edge : richer) {
            int rich = edge[0];
            int poor = edge[1];

            adj[poor].push_back(rich);
        }

        for (int i = 0; i < n; i++) {
            dfs(i);
        }

        return ans;
    }
};