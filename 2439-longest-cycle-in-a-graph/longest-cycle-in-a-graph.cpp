class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        vector<int> visited(n, -1);
        int ans = -1;
        int timer = 0;

        for (int i = 0; i < n; i++) {

            if (visited[i] != -1)
                continue;

            int node = i;
            int startTime = timer;

            while (node != -1 && visited[node] == -1) {
                visited[node] = timer++;
                node = edges[node];
            }

            // If node belongs to current traversal
            if (node != -1 && visited[node] >= startTime) {
                ans = max(ans, timer - visited[node]);
            }
        }

        return ans;
    }
};