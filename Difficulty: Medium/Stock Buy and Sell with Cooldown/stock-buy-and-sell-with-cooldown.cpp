class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int idx,int flag,vector<int> &arr,int n){
        if(idx>=n) return 0;
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        int take = -1e9,notTake = -1e9;
        if(flag==0){
            take = -arr[idx]+recFind(idx+1,1,arr,n);
        }
        else{
           take = arr[idx]+recFind(idx+2,0,arr,n);
        }
        notTake = recFind(idx+1,flag,arr,n);
        return dp[idx][flag]=max(take,notTake);
    }
  
    int maxProfit(vector<int>& arr) {
        // code here
        int n = arr.size();
        dp.resize(n,vector<int> (2,-1));
        return recFind(0,0,arr,n);
    }
};