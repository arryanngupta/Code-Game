class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int idx,vector<int>& val, vector<int>& wt, int capacity,int n){
        if(idx==n) return 0;
        if(dp[idx][capacity]!=-1) return dp[idx][capacity];
        int take = 0,notTake = 0;
        if(capacity>=wt[idx]){
            take = val[idx]+recFind(idx,val,wt,capacity-wt[idx],n);
        }
        notTake = recFind(idx+1,val,wt,capacity,n);
        return dp[idx][capacity]=max(take,notTake);
    }
  
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        dp.resize(n,vector<int> (capacity+1,-1));
        return recFind(0,val,wt,capacity,n);
    }
};