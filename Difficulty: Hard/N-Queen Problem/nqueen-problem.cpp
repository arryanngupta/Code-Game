class Solution {
  public:
  
    vector<vector<int>> mat,ans;
    
    bool isSafe(int row,int col,int n){
        for(int i = 0; i<row; i++) if(mat[i][col]) return false;
        for(int j = 0; j<col; j++) if(mat[row][j]) return false;
        int i = row,j = col;
        while(i>=0 && j>=0) if(mat[i--][j--]) return false;
        i = row,j = col;
        while(i>=0 && j<n) if(mat[i--][j++]) return false;
        return true;
    }
  
    void recFind(int row,vector<int> a,int n){
        if(row==n){
            if(a.size()) ans.push_back(a);
            return ;
        }
        for(int col = 0; col<n; col++){
            if(isSafe(row,col,n)){
                mat[row][col] = 1;
                a.push_back(col+1);
                recFind(row+1,a,n);
                mat[row][col] = 0;
                a.pop_back();
            }
        }
    }
  
    vector<vector<int>> nQueen(int n) {
        // code here
        mat.resize(n,vector<int> (n,0));
        ans.resize(n);
        vector<int> a;
        ans.clear();
        recFind(0,a,n);
        return ans;
    }
};