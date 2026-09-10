class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<vector<int>> adjrev(V);
        vector<int> indegree(V, 0);

        for (int node = 0; node < V; node++) {
            for (int it : graph[node]) {
                adjrev[it].push_back(node);
                indegree[node]++;
            }
        }
        queue<int> q;

        for (int node = 0; node < V; node++) {
            if (indegree[node] == 0) {
                q.push(node);
            }
        }

        vector<int> ans;

        while( !q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for ( int it :adjrev[node]) {
                indegree[it]--;

                if ( indegree[it] ==0) {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};