class Solution {
  public:
  
    vector<vector<int>> adjList;
    vector<int> ans;
  
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
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
            ans.push_back(node);
            for(auto it: adjList[node]){
                inDeg[it]--;
                if(inDeg[it]==0) q.push(it);
            }
        }
        vector<int> temp;
        return (ans.size()==n)?ans:temp; 
    }
};