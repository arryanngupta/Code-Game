class Solution {
  public:
  
    vector<vector<int>> adjList;
    int cnt = 0;
  
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        adjList.resize(n);
        vector<int> inDeg(n,0);
        for(auto it: prerequisites){
            adjList[it[1]].push_back(it[0]);
            inDeg[it[0]]++;
        }
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }   
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adjList[node]){
                inDeg[it]--;
                if(inDeg[it]==0) q.push(it);
            }
        }
        return (cnt==n);
    }
};