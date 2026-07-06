class Solution {
  public:
  
    vector<int> visited;
    vector<vector<pair<int,int>>> adjList;
    stack<int> st;
    
    void dfs(int node){
        visited[node] = 1;
        for(auto it: adjList[node]){
            if(!visited[it.first]) dfs(it.first);
        }
        st.push(node);
    }
  
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        visited.resize(V);
        adjList.resize(V);
        for(auto it: edges){
            adjList[it[0]].push_back({it[1],it[2]});
        }
        for(int i = 0; i<V; i++){
            if(!visited[i]) dfs(i);
        }
        vector<int> dist(V,1e9);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            for(auto it: adjList[node]){
                int adjNode = it.first,wt = it.second;
                if(dist[node]+wt<dist[adjNode]){
                    dist[adjNode] = dist[node]+wt;
                }
            }
            st.pop();
        }
        for(int i= 0; i<V; i++) if(dist[i]==1e9) dist[i] = -1;
        return dist;
    }
};
