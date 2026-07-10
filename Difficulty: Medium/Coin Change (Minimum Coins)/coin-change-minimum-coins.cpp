class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int idx,int sum,vector<int> &coins,int n){
        if(sum==0) return 0;
        if(idx==n) return 1e9;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int take = 1e9,notTake = 1e9;
        if(sum>=coins[idx]){
            take = 1+recFind(idx,sum-coins[idx],coins,n);
            // take = 1+recFind(idx+1,sum-coins[idx],coins,n);
        }
        notTake = recFind(idx+1,sum,coins,n);
        return dp[idx][sum]=min(take,notTake);
    }
  
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n = coins.size();
        dp.resize(n,vector<int> (sum+1,-1));
        sort(coins.begin(),coins.end(),greater<int> ());
        int ans = recFind(0,sum,coins,n);
        if(ans>=1e9) return -1;
        return ans;
    }
};