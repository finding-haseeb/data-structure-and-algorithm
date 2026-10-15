class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }

        vector<double> prob(n, 0);
        prob[start_node] = 1.0;

        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});

        while(!pq.empty()) {
            auto [currProb,node] = pq.top();
            pq.pop();

            if(node == end_node) {
                return currProb;
            }

            if(currProb < prob[node]) continue;

            for(auto [neighbour,p] : adj[node]) {
                double newProb = currProb * p;

                if(newProb > prob[neighbour]) {
                    prob[neighbour] = newProb;
                    pq.push({newProb,neighbour});
                }
            }
        }

        return 0.0;
    }
};