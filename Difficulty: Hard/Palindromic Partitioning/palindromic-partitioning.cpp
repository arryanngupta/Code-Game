class Solution {
  public:
  
    vector<int> dp;
    vector<vector<int>> pal;
  
    int recFind2(int i,int j,string &s,int n){
        if(i>j) return 1;
        if(pal[i][j]!=-1) return pal[i][j];
        int ans = 0;
        if(s[i]==s[j]){
            ans = recFind2(i+1,j-1,s,n);
        }
        return pal[i][j]=ans;
    }
    
    int recFind(int idx,string &s,int n){
        if(idx==n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans = 1e9;
        for(int i = idx; i<n; i++){
            if(pal[idx][i]){
                if(i==n-1) ans = min(ans,recFind(i+1,s,n));
                else ans = min(ans,1+recFind(i+1,s,n));
            }
        }
        return dp[idx]=ans;
    }
  
    int palPartition(string &s) {
        // code here
        int n = s.size();
        dp.resize(n,-1);
        pal.resize(n,vector<int> (n,-1));
        // recFind2(0,n-1,s,n);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                pal[i][j] = recFind2(i,j,s,n);
            }
        }
        return recFind(0,s,n);
    }
};