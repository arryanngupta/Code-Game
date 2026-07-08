class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int row,int col,vector<vector<int>>& mat,int n,int m){
        if(row==n-1) return mat[row][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int ans = 1e9;
        if(row+1<n){
            ans = mat[row][col]+recFind(row+1,col,mat,n,m);
        }
        if(row+1<n && col-1>=0){
            ans = min(ans,mat[row][col]+recFind(row+1,col-1,mat,n,m));
        }
        if(row+1<n && col+1<m){
            ans = min(ans,mat[row][col]+recFind(row+1,col+1,mat,n,m));
        }
        return dp[row][col]=ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& mat) {
        // code here
        int n = mat.size(),m = mat[0].size();
        int mini = 1e9;
        dp.resize(n,vector<int> (m,-1));
        for(int i = 0; i<m; i++){
            mini = min(mini,recFind(0,i,mat,n,m));
        }
        return mini;
    }
};
