class Solution {
  public:
  
    vector<vector<vector<int>>> dp;
  
    int recFind(int i,int j1,int j2,vector<vector<int>>& grid,int n,int m){
        if(i==n) return 0;
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int ans = 0,val = 0;
        if(j1==j2){
            val = grid[i][j1];
        }
        else{
            val = grid[i][j1]+grid[i][j2];
        }
        for(int j = -1; j<=1; j++){
            for(int k = -1; k<=1; k++){
                int nc1 = j1+j,nc2 = j2+k;
                if(nc1>=0 && nc1<m && nc2>=0 && nc2<m){
                    ans = max(ans,val+recFind(i+1,nc1,nc2,grid,n,m));
                }
            }
        }
        return dp[i][j1][j2]=ans;
    }
  
    int maxChocolate(vector<vector<int>>& grid) {
        // code here
        int n = grid.size(),m = grid[0].size();
        dp.resize(n,vector<vector<int>> (m,vector<int> (m,-1)));
        return recFind(0,0,m-1,grid,n,m);
    }
};