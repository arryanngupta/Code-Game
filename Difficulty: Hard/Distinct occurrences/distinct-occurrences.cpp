class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int i,int j,string &txt, string &pat,int n,int m){
        if(i==n || j==m) return (j==m);
        if(dp[i][j]!=-1) return dp[i][j];
        int take = 0,notTake = 0;
        if(txt[i]==pat[j]){
            take = recFind(i+1,j+1,txt,pat,n,m);
        }
        notTake = recFind(i+1,j,txt,pat,n,m);
        return dp[i][j]=(take+notTake);
    }
    
    int subseqCount(string &txt, string &pat) {
        // code here
        int n = txt.size(),m = pat.size();
        dp.resize(n,vector<int> (m,-1));
        return recFind(0,0,txt,pat,n,m);
    }
};