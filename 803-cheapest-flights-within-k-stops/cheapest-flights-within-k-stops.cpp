class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int, int>>>adjlist(n);

        for ( auto it : flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adjlist[u].push_back( { v , wt});
        }

        queue<pair<int, pair<int , int>>>q;
        q.push({0 , { src, 0}});
        vector<int> distance( n , 1e9);
        distance[src]= 0;

        while( !q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;

            q.pop();


            if (stops > k) {
                continue;
            }

            for ( auto it : adjlist[node]) {
                int neighbour = it.first;
                int price = it.second;

                if ( cost + price  < distance[neighbour] && stops <= k) {
                    distance[neighbour] = cost + price;
                        q.push( {stops+1 , {neighbour , cost + price}});
                }
            }
        }
        if ( distance[dst] == 1e9 ) return -1;
        return distance[dst];
        
    }
};