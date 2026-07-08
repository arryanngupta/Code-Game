class Solution {
  public:
  
    vector<vector<int>> dp;
    
    int recFind(int row,int col,vector<vector<int>> &grid,int n,int m){
        if(row==(n-1) && col==(m-1)) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        int right = 0,down = 0;
        if(col+1<m && grid[row][col+1]==0){
            right = recFind(row,col+1,grid,n,m);
        }
        if(row+1<n && grid[row+1][col]==0){
            down = recFind(row+1,col,grid,n,m);
        }
        return dp[row][col]=(right+down);
    }
  
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        int n = grid.size(),m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1]==1) return 0;
        dp.resize(n,vector<int> (m,-1));
        return recFind(0,0,grid,n,m);
    }
};