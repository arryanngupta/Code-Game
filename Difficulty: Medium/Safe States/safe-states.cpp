class Solution {
  public:
  
    vector<int> ans,path,check,visited;
    vector<vector<int>> adjList;
    
    bool dfs(int node){
        visited[node] = 1;
        path[node] = 1;
        check[node] = 0;
        for(auto it: adjList[node]){
            if(!visited[it]){
                if(dfs(it)){
                    return true;
                }
            }
            else if(path[it]){
                return true;
            }
        }
        check[node] = 1;
        path[node]=0;
        return false;
    }
    
    
    vector<int> safeNodes(int V, vector<vector<int>>& edges) {
        // Code here
        adjList.resize(V);
        path.resize(V);
        check.resize(V);
        visited.resize(V);
        for(auto it: edges){
            adjList[it[0]].push_back(it[1]);
        }
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        for(int i = 0; i<V; i++){
            if(check[i]) ans.push_back(i);
        }
        return ans;
    }
};