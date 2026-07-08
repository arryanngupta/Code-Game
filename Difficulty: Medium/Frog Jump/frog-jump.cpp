class Solution {
  public:
  
    vector<int> dp;
  
    int recFind(int idx,vector<int>& height,int n){
        if(idx==n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int one = 1e9,two = 1e9;
        if((idx+1)<n){
            one = abs(height[idx]-height[idx+1])+recFind(idx+1,height,n);
        }
        if((idx+2)<n){
            two = abs(height[idx]-height[idx+2])+recFind(idx+2,height,n);
        }
        return dp[idx]=min(one,two);
    }
  
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        dp.resize(n,-1);
        return recFind(0,height,n);
    }
};