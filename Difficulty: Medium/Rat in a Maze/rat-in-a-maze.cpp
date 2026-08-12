class Solution {
  public:
  
    vector<vector<int>> visited;
    vector<string> ans;
  
    void recFind(int row,int col,string s,vector<vector<int>>& maze,int n){
        if(row==n-1 && col==n-1){
            ans.push_back(s);
            return ;
        }
        for(int i = -1; i<=1; i++){
            for(int j = -1; j<=1; j++){
                if((i==0 && j==0) || (i!=0 && j!=0)) continue;
                int nr = i+row,nc = j+col;
                if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc] && 
                maze[nr][nc]){
                    if(i==-1) s += 'U';
                    else if(i==1) s += 'D';
                    else if(j==-1) s += 'L';
                    else if(j==1) s += 'R';
                    visited[nr][nc] = 1;
                    recFind(nr,nc,s,maze,n);
                    visited[nr][nc] = 0;
                    s.pop_back();
                }
            }
        }
    }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        if(maze[0][0]==0 || maze[n-1][n-1]==0) return {};
        visited.resize(n,vector<int> (n,0));
        visited[0][0] = 1;
        ans.clear();
        recFind(0,0,"",maze,n);
        sort(ans.begin(),ans.end());
        return ans;
    }
};