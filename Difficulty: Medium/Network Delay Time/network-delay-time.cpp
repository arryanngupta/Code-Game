class Solution {
  public:
    int findDelayTime(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<pair<int,int>>> adjList(V);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adjList[u].push_back({v,wt});
        }
        vector<int> dist(V,1e9);
        // {dist,node}
        priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        pq.push({0,src});
        dist[src] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int distance = pq.top().first;
            pq.pop();
            if(distance>dist[node]) continue;
            for(auto it: adjList[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(distance+wt<dist[adjNode]){
                    dist[adjNode] = distance+wt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int maxi = 0;
        for(int i = 0; i<V; i++){
            if(dist[i]==1e9) return -1;
            maxi = max(maxi,dist[i]);
        }
        return maxi;
    }
};