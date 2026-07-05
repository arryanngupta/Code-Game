class Solution {
  public:
  
    vector<vector<int>> adjList;
    vector<int> visited,path;
    
    bool dfs(int node){
        visited[node] = 1;
        path[node] = 1;
        for(auto it: adjList[node]){
            if(!visited[it]){
                if(dfs(it)) return true;
            }
            else if(path[it]) return true;
        }
        path[node]=0;
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        visited.resize(V,0);
        path.resize(V,0);
        adjList.resize(V);
        for(auto it: edges){
            adjList[it[0]].push_back(it[1]);
        }
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                if(dfs(i)) return true;
            }
        }
        return false;
    }
};