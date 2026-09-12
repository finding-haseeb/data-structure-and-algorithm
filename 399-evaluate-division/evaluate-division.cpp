class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;

        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];

            adj[a].push_back({b, val});
            adj[b].push_back({a, 1.0 / val});
        }

        vector<double> ans;

        for (auto& query : queries) {
            string src = query[0];
            string dest = query[1];

            if (!adj.count(src) || !adj.count(dest)) {
                ans.push_back(-1.0);
                continue;
            }

            if (src == dest) {
                ans.push_back(1.0);
                continue;
            }

            queue<pair<string, double>> q;
            unordered_set<string> visited;

            q.push({src, 1.0});
            visited.insert(src);

            double result = -1.0;

            while (!q.empty()) {
                auto [node, value] = q.front();
                q.pop();

                if (node == dest) {
                    result = value;
                    break;
                }

                for (auto& [next, weight] : adj[node]) {
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push({next, value * weight});
                    }
                }
            }

            ans.push_back(result);
        }

        return ans;
    }
};