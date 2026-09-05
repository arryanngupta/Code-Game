class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int i,int j,vector<int> &arr,int n){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = 1e9;
        for(int k = i; k<j; k++){
            mini = min(mini,arr[i-1]*arr[k]*arr[j]+recFind(i,k,arr,n)+recFind(k+1,j,arr,n));
        }
        return dp[i][j]=mini;
    }
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        dp.resize(n,vector<int> (n,-1));
        return recFind(1,n-1,arr,n);
    }
};
