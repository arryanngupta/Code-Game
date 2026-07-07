class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adjList(V);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        
        vector<int> dist(V,1e9),ways(V);
        
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>> > pq;
        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            int distance = pq.top().first,node = pq.top().second;
            pq.pop();
            for(auto it: adjList[node]){
                int adjNode = it.first,wt = it.second;
                if(distance+wt<dist[adjNode]){
                    dist[adjNode] = distance+wt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode],adjNode});
                }
                else if(distance+wt==dist[adjNode]){
                    ways[adjNode]+=ways[node];
                }
            }
        }
        return ways[V-1];
    }
};