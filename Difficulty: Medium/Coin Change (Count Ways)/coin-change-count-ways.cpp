class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int idx,vector<int>& coins, int sum,int n){
        if(idx==n) return (sum==0);
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int ans = 0;
        if(sum>=coins[idx]){
            ans += recFind(idx,coins,sum-coins[idx],n);
        }
        ans += recFind(idx+1,coins,sum,n);
        return dp[idx][sum]=ans;
    }
  
    int count(vector<int>& coins, int sum) {
        // code here.
        int n = coins.size();
        dp.resize(n,vector<int> (sum+1,-1));
        return recFind(0,coins,sum,n);
    }
};