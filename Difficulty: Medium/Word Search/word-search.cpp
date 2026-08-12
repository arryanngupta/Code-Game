class Solution {
  public:
  
    vector<vector<int>> visited;
  
    bool dfs(int row,int col,int idx,vector<vector<char>> &mat, string &word){
        if(idx>=word.size()) return true;
        visited[row][col] = 1;
        for(int i = -1; i<=1; i++){
            for(int j = -1; j<=1; j++){
                if((i==0 && j==0)||(i!=0 && j!=0)) continue;
                int nr = i+row,nc = j+col;
                if(nr>=0 && nr<mat.size() && nc>=0 && nc<mat[0].size() &&
                !visited[nr][nc] && mat[nr][nc]==word[idx]){
                    if(dfs(nr,nc,idx+1,mat,word)) return true;
                }
            }
        }
        visited[row][col] = 0;
        return false;
    }
  
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        int n = mat.size(),m = mat[0].size();
        visited.resize(n,vector<int> (m,0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]==word[0]){
                    if(dfs(i,j,1,mat,word)) return true;
                }
            }
        }
        return false;
    }
};