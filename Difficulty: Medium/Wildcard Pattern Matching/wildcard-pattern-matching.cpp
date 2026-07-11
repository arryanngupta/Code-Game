class Solution {
  public:
  
    vector<vector<int>> dp;
  
    bool recFind(int i,int j,string &txt, string &pat,int n,int m){
        if(i==n && j==m) return true;
        if(i==n){
            while(j<m && pat[j]=='*'){
                j++;
            }
            return (j==m);
        }
        if(i==n || j==m) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans = false;
        if(txt[i]==pat[j] || pat[j]=='?'){
            ans = recFind(i+1,j+1,txt,pat,n,m);
        }
        else if(pat[j]=='*'){
            ans = recFind(i,j+1,txt,pat,n,m);
            ans = ans||recFind(i+1,j,txt,pat,n,m);
        }
        return dp[i][j]=ans;
    }
  
    bool wildCard(string &txt, string &pat) {
        // code here
        int n = txt.size(),m = pat.size();
        dp.resize(n,vector<int> (m,-1));
        return recFind(0,0,txt,pat,n,m);
    }
};