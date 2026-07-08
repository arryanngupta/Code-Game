class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int i,int j,int n,vector<vector<int>>& triangle){
        if(i==n-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1e9;
        ans = triangle[i][j]+recFind(i+1,j,n,triangle);
        if(j<=i) ans = min(ans,triangle[i][j]+recFind(i+1,j+1,n,triangle));
        return dp[i][j]=ans;
    }
  
    int minPathSum(vector<vector<int>>& triangle) {
        // Code here
        int n = triangle.size();
        dp.resize(n);
        for(int i = 0; i<n; i++){
            dp[i].resize(i+1,-1);
        }
        return recFind(0,0,n,triangle);
    }
};