class Solution {
  public:
  
    vector<vector<int>> adjList;
    vector<int> visited;
    
    void dfs(int node,int c,int d){
        visited[node] = 1;
        for(auto it: adjList[node]){
            if((node==c&& it==d) || (node==d && it==c)) continue;
            if(!visited[it]) dfs(it,c,d);
        }
    }
  
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        visited.assign(V,0);
        adjList.assign(V,{});
        for(auto it: edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        int cnt1 = 0;
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                cnt1++;
                dfs(i,-1,-1);
            }
        }
        visited.assign(V,0);
        int cnt2 = 0;
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                cnt2++;
                dfs(i,c,d);
            }
        }
        return (cnt2-cnt1==1);
    }
};