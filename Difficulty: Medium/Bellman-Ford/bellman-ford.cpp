class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V,1e8);
        dist[src] = 0;
        for(int i = 0; i<=V-1; i++){
            for(auto it: edges){
                int u = it[0],v = it[1],wt = it[2];
                if(dist[u] != 1e8 && dist[u]+wt<dist[v]){
                    if(i==(V-1)) return {-1};
                    dist[v] = dist[u]+wt;
                }
            }
        }
        return dist;
    }
};
