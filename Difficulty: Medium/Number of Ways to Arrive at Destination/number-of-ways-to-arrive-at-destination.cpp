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
        vector<pair<int,int>> dist(V,{1e9,0});
        priority_queue<pair<pair<int,int>,int>,
        vector<pair<pair<int,int>,int>>,
        greater<pair<pair<int,int>,int>> > pq; // {{distance,no},node}
        pq.push({{0,0},0});
        dist[0].first = 0;
        int ans = 0;
        while(!pq.empty()){
            int distance = pq.top().first.first;
            int no = pq.top().first.second;
            int node = pq.top().second;
            pq.pop();
            if (distance > dist[node].first) continue;
            for(auto it: adjList[node]){
                int adjNode = it.first,wt = it.second;
                if(distance+wt<dist[adjNode].first){
                    dist[adjNode].first = distance+wt;
                    dist[adjNode].second=1;
                    pq.push({dist[adjNode],adjNode});
                }
                else if(distance+wt==dist[adjNode].first){
                    dist[adjNode].second++;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist[V-1].second;
    }
};