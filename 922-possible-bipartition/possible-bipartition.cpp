class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);

        for (auto &it : dislikes) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n + 1, -1);

        for (int i = 1; i <= n; i++) {
            if (color[i] != -1)
                continue;

            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbour : adj[node]) {
                    if (color[neighbour] == -1) {
                        color[neighbour] = 1 - color[node];
                        q.push(neighbour);
                    }
                    else if (color[neighbour] == color[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};