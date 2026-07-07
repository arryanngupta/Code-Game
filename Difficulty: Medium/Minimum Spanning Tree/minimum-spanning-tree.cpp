class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adjList(V);
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>> > pq;
        pq.push({0,0});
        vector<int> visited(V,0);
        int sum = 0;
        while(!pq.empty()){
            int distance = pq.top().first,node = pq.top().second;
            pq.pop();
            if(visited[node]) continue;
            visited[node] = 1;
            sum += distance;
            for(auto it: adjList[node]){
                int adjNode = it.first,wt = it.second;
                if(!visited[adjNode]){
                    pq.push({wt,adjNode});
                }
            }
        }
        return sum;
    }
};