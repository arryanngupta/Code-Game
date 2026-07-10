class Solution {

  public:
  
    vector<vector<int>> dp;
  
    int recFind(int i,int j,string &s1, string &s2,int n,int m){
        if(j==m) return n-i;
        if(i==n) return m-j;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        if(s1[i]==s2[j]){
            ans = recFind(i+1,j+1,s1,s2,n,m);
        }
        else{
            ans = min(min(1+recFind(i+1,j,s1,s2,n,m),1+recFind(i,j+1,s1,s2,n,m)),
            2+recFind(i+1,j+1,s1,s2,n,m));
        }
        return dp[i][j]=ans;
    }
    
    int minOperations(string &s1, string &s2) {
        // Your code goes here
        int n = s1.size(),m = s2.size();
        dp.resize(n,vector<int> (m,-1));
        return recFind(0,0,s1,s2,n,m);
    }
};