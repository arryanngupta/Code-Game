class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int i,int j,string &s1, string &s2,int n,int m){
        if(i==n || j==m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(s1[i]==s2[j]){
            ans = 1+recFind(i+1,j+1,s1,s2,n,m);
        }
        return dp[i][j]=ans;
    }
  
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int n = s1.size(),m = s2.size();
        dp.resize(n,vector<int> (m,-1));
        int maxi = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                maxi = max(maxi,recFind(i,j,s1,s2,n,m));
            }
        }
        return maxi;
    }
};