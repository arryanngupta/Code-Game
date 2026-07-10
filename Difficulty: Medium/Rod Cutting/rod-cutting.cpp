class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int idx,int len,vector<int> &price,int n){
        if(len==0) return 0;
        if(idx==n) return -1e9;
        if(dp[idx][len]!=-1) return dp[idx][len];
        int take = 0,notTake = 0;
        if(len>=(idx+1)){
            take = price[idx]+recFind(idx,len-(idx+1),price,n);
        }
        notTake = recFind(idx+1,len,price,n);
        return dp[idx][len]=max(take,notTake);
    }
  
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        dp.resize(n,vector<int> (n+1,-1));
        return recFind(0,n,price,n);
    }
};