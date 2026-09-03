class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int idx,int prev,vector<int>& arr,int n){
        if(idx>=n) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int take = 0,notTake = 0;
        if(prev==-1 || arr[idx]>arr[prev]){
            take = 1+recFind(idx+1,idx,arr,n);
        }
        notTake = recFind(idx+1,prev,arr,n);
        return dp[idx][prev+1]=max(take,notTake);
    }
  
    int lis(vector<int>& arr) {
        // code here
        int n = arr.size();
        dp.resize(n,vector<int> (n+1,-1));
        return recFind(0,-1,arr,n);
    }
};