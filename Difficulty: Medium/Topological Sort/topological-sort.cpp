class Solution {
  public:
  
    vector<int> ans;
    vector<vector<int>> adjList;
    
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        adjList.resize(V);
        vector<int> inDeg(V,0);
        for(auto it: edges){
            adjList[it[0]].push_back(it[1]);
            inDeg[it[1]]++;
        }
        queue<int> q;
        for(int i = 0; i<V; i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }   
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adjList[node]){
                inDeg[it]--;
                if(inDeg[it]==0) q.push(it);
            }
        }
        return ans;
    }
};