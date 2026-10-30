class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
        }

        const int INF = 1e9;

        vector<vector<int>> dist(n, vector<int>(k + 1, INF));

        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {
            auto [cost, node, cnt] = pq.top();
            pq.pop();

            if(cost != dist[node][cnt])
                continue;

            if(node == n - 1)
                return cost;

            for(auto [next, wt] : adj[node]) {
                int newCnt;

                if(labels[node] == labels[next])
                    newCnt = cnt + 1;
                else
                    newCnt = 1;

                if(newCnt > k)
                    continue;

                int newCost = cost + wt;

                if(newCost < dist[next][newCnt]) {
                    dist[next][newCnt] = newCost;
                    pq.push({newCost, next, newCnt});
                }
            }
        }

        return -1;
    }
};