class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
        // code here
        vector<vector<int>> adjList(V);
        for(auto it: edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>> q;
        q.push({0,src});
        vector<int> dist(V,1e9);
        dist[src] = 0;
        while(!q.empty()){
            int distance = q.front().first,node = q.front().second;
            q.pop();
            if(distance>dist[node]) continue;
            for(auto it: adjList[node]){
                if(distance+1<dist[it]){
                    dist[it] = distance+1;
                    q.push({dist[it],it});
                }
            }
        }
        if(dist[dest]==1e9) return -1;
        return dist[dest];
    }
};
