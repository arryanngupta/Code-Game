class Solution {
  public:
    
    vector<vector<int>> adjList;
    vector<int> visited;
    stack<int> st;
    
    void dfs(int node){
        visited[node] = 1;
        for(auto it: adjList[node]){
            if(!visited[it]){
                dfs(it);
            }
        }
        st.push(node);
    }
    
    void dfs2(int node){
        visited[node] = 1;
        for(auto it: adjList[node]){
            if(!visited[it]){
                dfs2(it);
            }
        }
    }
  
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        adjList.resize(V);
        for(auto it: edges){
            adjList[it[0]].push_back(it[1]);
        }
        visited.resize(V);
        for(int i= 0; i<V; i++){
            if(!visited[i]) dfs(i);
        }
        adjList.assign(V,{});
        for(auto it: edges){
            adjList[it[1]].push_back(it[0]);
        }
        visited.assign(V,0);
        int ans = 0;
        while(!st.empty()){
            int node = st.top();
            if(!visited[node]){
                dfs2(node);
                ans++;
            }
            st.pop();
        }
        return ans;
    }
};