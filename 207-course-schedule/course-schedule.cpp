class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int V = numCourses;
        vector<vector<int>> adjlist(V);
        vector<int> indegree( V,0);

        for ( auto it : prerequisites) {
            int first= it[0];
            int second= it[1];

            adjlist[second].push_back( first);
            indegree[first]++;
        }

        queue<int> q;
        for ( int i =0; i < V ; i++) {
            if ( indegree[i] == 0) {
                q.push(i);
            }
        }
        int count =0;

        while( !q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for ( auto it : adjlist[node]) {
                indegree[it] --;

                if ( indegree[it] == 0) {
                    q.push( it);
                }
            }
        }
        if( count == V) return true;
        return false;
    }
};