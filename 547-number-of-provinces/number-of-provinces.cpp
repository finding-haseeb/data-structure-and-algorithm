class Solution {
    void dfs( vector<vector<int>> &adjlist, vector<int> & visited, int node) {
        visited[node] =1 ;
        
        for( auto it : adjlist[node]) {
            if( !visited[it]) {
                dfs( adjlist, visited, it);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        //matrix to adj list
        int v = isConnected.size();

        vector<vector<int>> adjlist(v);
        for(int i =0; i <v ; i++) {
            for(int j =0; j < v ; j++) {
                if( isConnected[i][j]==1 && i != j ) {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        vector<int> visited( v, 0);
        int count =0;
        for(int i =0 ; i <v ; i++) {
            if(!visited[i]){
                count++;
                dfs(adjlist, visited, i);
            }

        }
     return count;   
    }
};