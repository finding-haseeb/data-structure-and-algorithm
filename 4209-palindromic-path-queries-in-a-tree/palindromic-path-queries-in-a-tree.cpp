class Solution {
public:
    int LOG, timer;
    vector<vector<int>> adj, up;
    vector<int> tin, tout, bit, mask;

    void add(int idx, int val, int n) {
        while(idx <= n) {
            bit[idx] ^= val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int ans = 0;

        while(idx > 0) {
            ans ^= bit[idx];
            idx -= idx & -idx;
        }

        return ans;
    }

    void rangeXor(int l, int r, int val, int n) {
        add(l, val, n);
        add(r + 1, val, n);
    }

    void dfs(int node, int par) {
        tin[node] = ++timer;
        up[0][node] = par;

        for(int i = 1; i < LOG; i++) {
            up[i][node] = up[i - 1][up[i - 1][node]];
        }

        for(int child : adj[node]) {
            if(child == par) continue;

            dfs(child, node);
        }

        tout[node] = timer;
    }

    bool isAncestor(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int lca(int u, int v) {
        if(isAncestor(u, v)) return u;
        if(isAncestor(v, u)) return v;

        for(int i = LOG - 1; i >= 0; i--) {
            if(!isAncestor(up[i][u], v)) {
                u = up[i][u];
            }
        }

        return up[0][u];
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {

        LOG = 1;
        while((1 << LOG) <= n) {
            LOG++;
        }

        timer = 0;

        adj.assign(n, {});
        up.assign(LOG, vector<int>(n));
        tin.assign(n, 0);
        tout.assign(n, 0);
        bit.assign(n + 2, 0);
        mask.assign(n, 0);

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, 0);

        for(int i = 0; i < n; i++) {
            mask[i] = 1 << (s[i] - 'a');

            rangeXor(tin[i], tout[i], mask[i], n);
        }

        vector<bool> ans;

        for(string q : queries) {
            string type;
            int u;
            string temp;

            stringstream ss(q);
            ss >> type >> u >> temp;

            if(type == "update") {
                char c = temp[0];

                int newMask = 1 << (c - 'a');
                int change = mask[u] ^ newMask;

                rangeXor(tin[u], tout[u], change, n);

                mask[u] = newMask;
            }
            else {
                int v = stoi(temp);

                int w = lca(u, v);

                int x = query(tin[u]);
                int y = query(tin[v]);

                int path = x ^ y ^ mask[w];

                if((path & (path - 1)) == 0) {
                    ans.push_back(true);
                }
                else {
                    ans.push_back(false);
                }
            }
        }

        return ans;
    }
};