class Solution {
  public:
  
    vector<vector<int>> adjList;
    vector<int> color,dp;
    
    bool isPoss(int node,int col,int v){
        for(auto it: adjList[node]){
            if(color[it]==col) return false;
        }
        return true;
    }
    
    int recFind(int node,int v,int m){
        if(node==v) return 1;
        // if(dp[node]!=-1) return dp[node];
        for(int col = 1; col<=m; col++){
            if(isPoss(node,col,v)){
                color[node] = col;
                if(recFind(node+1,v,m)) return 1;
                color[node] = 0;
            }
        }
        return dp[node]=0;
    }
  
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        color.resize(v,0);
        dp.resize(v,-1);
        adjList.resize(v);
        for(auto it: edges){
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }
        return recFind(0,v,m);
    }
};