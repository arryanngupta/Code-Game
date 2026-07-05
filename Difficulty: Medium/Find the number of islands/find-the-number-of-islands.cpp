class Solution {
  public:
  
    vector<vector<int>> visited;
    
    void dfs(int row,int col,vector<vector<char>>& grid,int n,int m){
        visited[row][col]=1;
        for(int i = -1; i<=1; i++){
            for(int j = -1; j<=1; j++){
                if((i==0 && j==0)) continue;
                int nr = i+row,nc = j+col;
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='L' && !visited[nr][nc]){
                    dfs(nr,nc,grid,n,m);
                }
            }
        }
    }
  
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(),m = grid[0].size(),num = 0;
        visited.resize(n,vector<int> (m,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j]=='L' && !visited[i][j]){
                    num++;
                    dfs(i,j,grid,n,m);
                }
            }
        }
        return num;
    }
};