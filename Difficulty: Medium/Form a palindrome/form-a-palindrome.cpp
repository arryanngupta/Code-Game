class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int i,int j,string &s,int n){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(s[i]==s[j]){
            ans = recFind(i+1,j-1,s,n);
        }
        else{
            ans = 1+min(recFind(i,j-1,s,n),recFind(i+1,j,s,n));
        }
        return dp[i][j]=ans;
    }
    
  
    int findMinInsertions(string &s) {
        // code here
        int n = s.size();
        dp.resize(n,vector<int> (n,-1));
        return recFind(0,n-1,s,n);
    }
};