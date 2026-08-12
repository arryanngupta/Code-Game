class Solution {
  public:
  
    vector<pair<int,int>> a;
    
    bool isPoss(int val,int row,int col,vector<vector<int>> &mat){
        for(int i = 0; i<9; i++) if(mat[i][col]==val || mat[row][i]==val) return false;
        int i = 3*(row/3),iE = i+3;
        int j = 3*(col/3),jE = j+3;
        for(int x = i; x<iE; x++){
            for(int y = j; y<jE; y++){
                if(mat[x][y]==val) return false;
            }
        }
        return true;
    }
  
    bool recFind(int idx,vector<pair<int,int>> &a,vector<vector<int>> &mat,int n){
        if(idx>=n) return true;
        int row = a[idx].first,col = a[idx].second;
        for(int i = 1; i<10; i++){
            if(isPoss(i,row,col,mat)){
                mat[row][col] = i;
                if(recFind(idx+1,a,mat,n)) return true;
                mat[row][col] = 0;
            }
        }
        return false;
    }
  
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        a.clear();
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(!mat[i][j]){
                    a.push_back({i,j});
                }
            }
        }
        if(a.empty()) return ;
        int n = a.size();
        recFind(0,a,mat,n);
    }
};