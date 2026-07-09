class Solution {
  public:
  
    vector<vector<int>> dp;
  
    bool recFind(int idx,int sum,vector<int>& arr,int n){
        if(sum==0) return true;
        if(idx==n) return false;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool take = false,notTake = false;
        if(sum>=arr[idx]){
            take = recFind(idx+1,sum-arr[idx],arr,n);
        }
        notTake = recFind(idx+1,sum,arr,n);
        return dp[idx][sum]=take||notTake;
    }
  
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = 0;
        for(auto it: arr) sum += it;
        if(sum%2!=0) return false;
        int n = arr.size();
        dp.resize(n,vector<int> (sum/2+1,-1));
        recFind(0,sum/2,arr,n);
    }
};