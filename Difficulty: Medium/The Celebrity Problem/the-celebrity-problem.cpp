class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        for(int i = 0; i<n; i++){
            int flag = 0;
            for(int j = 0; j<n; j++){
                if(i==j) continue;
                if(mat[i][j]){
                    flag = 1;
                    break;
                }
            }
            if(flag==0){
                for(int j = 0; j<n; j++){
                    if(mat[j][i]==0){
                        flag = 1;
                        break;
                    }
                }
                if(flag==0) return i;
            }
        }
        return -1;
    }
};