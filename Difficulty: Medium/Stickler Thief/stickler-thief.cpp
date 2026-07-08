class Solution {
  public:
  
    vector<int> dp;
  
    int recFind(int idx,vector<int>& arr,int n){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take = 0,notTake = 0;
        take = arr[idx]+recFind(idx+2,arr,n);
        notTake = recFind(idx+1,arr,n);
        return dp[idx]=max(take,notTake);
    }
  
    int findMaxSum(vector<int>& arr) {
        // code here
        int n = arr.size();
        dp.resize(n,-1);
        return recFind(0,arr,n);
    }
};