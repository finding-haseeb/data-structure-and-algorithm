class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int mod = 1e9 + 7;

        // Adjacency List
        vector<vector<pair<int, int>>> adjlist(n);

        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adjlist[u].push_back({v, wt});
            adjlist[v].push_back({u, wt});
        }

        // Distance and ways arrays
        vector<long long> distance(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        // Min Heap
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        distance[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {

            long long dist = pq.top().first;
            int node = pq.top().second;

            pq.pop();

            // Skip outdated entry
            if (dist > distance[node]) {
                continue;
            }

            for (auto it : adjlist[node]) {

                int neighbour = it.first;
                int weight = it.second;

                // Found shorter path
                if (dist + weight < distance[neighbour]) {

                    distance[neighbour] = dist + weight;

                    // Same number of ways as current node
                    ways[neighbour] = ways[node];

                    pq.push({distance[neighbour], neighbour});
                }

                // Found another shortest path
                else if (dist + weight == distance[neighbour]) {

                    ways[neighbour] =
                        (ways[neighbour] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};