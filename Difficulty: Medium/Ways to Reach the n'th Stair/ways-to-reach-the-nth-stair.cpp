class Solution {
  public:
  
    vector<int> dp;
  
    int recFind(int idx,int n){
        if(idx==n) return 1;
        if(idx>n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int one = 0,two = 0;
        one = recFind(idx+1,n);
        two = recFind(idx+2,n);
        return dp[idx]=(one+two);
    }
  
    int countWays(int n) {
        // code here
        dp.resize(n,-1);
        return recFind(0,n);
    }
};
