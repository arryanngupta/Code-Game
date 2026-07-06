class Solution {
  public:
    int findCheapestCost(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        // code here
        vector<vector<int>> dist(n,vector<int> (k+3,1e9));
        dist[src][1] = 0;
        priority_queue<pair<pair<int,int>,int>,
        vector<pair<pair<int,int>,int>>,
        greater<pair<pair<int,int>,int>> > pq;
        pq.push({{0,1},src}); // {{dist,k},node}
        vector<vector<pair<int,int>>> adjList(n);
        for(auto it: edges){
            adjList[it[0]].push_back({it[1],it[2]});
        }
        while(!pq.empty()){
            int distance = pq.top().first.first;
            int k1 = pq.top().first.second;
            int node = pq.top().second;
            pq.pop();
            if (distance > dist[node][k1]) continue;
            for(auto it: adjList[node]){
                int adjNode = it.first,wt = it.second;
                if(k1+1<=k+2 && distance+wt<dist[adjNode][k1+1]){
                    dist[adjNode][k1+1] = distance+wt;
                    pq.push({{dist[adjNode][k1+1],k1+1},adjNode});
                }
            }
        }
        int mini = 1e9;
        for(int i = 0; i<=k+2; i++){
            mini = min(mini,dist[dst][i]);
        }
        if(mini==1e9) return -1;
        return mini;
    }
};