class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int idx,int prev,vector<int>& r, vector<int>& g, vector<int>& b,int n){
        if(idx>=n) return 0;
        int ans = 1e9;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        if(prev==-1){
            ans = r[idx]+recFind(idx+1,0,r,g,b,n);
            ans = min(ans,g[idx]+recFind(idx+1,1,r,g,b,n));
            ans = min(ans,b[idx]+recFind(idx+1,2,r,g,b,n));
        }
        else if(prev==0){
            ans = min(ans,g[idx]+recFind(idx+1,1,r,g,b,n));
            ans = min(ans,b[idx]+recFind(idx+1,2,r,g,b,n));
        }
        else if(prev==1){
            ans = r[idx]+recFind(idx+1,0,r,g,b,n);
            ans = min(ans,b[idx]+recFind(idx+1,2,r,g,b,n));
        }
        else{
            ans = min(ans,g[idx]+recFind(idx+1,1,r,g,b,n));
            ans = min(ans,r[idx]+recFind(idx+1,0,r,g,b,n));
        }
        return dp[idx][prev+1]=ans;
    }
  
    int distinctColoring(vector<int>& r, vector<int>& g, vector<int>& b) {
        // code here
        int n = r.size();
        dp.resize(n,vector<int> (4,-1));
        return recFind(0,-1,r,g,b,n);
    }
};