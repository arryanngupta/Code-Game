class Solution {
  public:
  
    vector<vector<vector<int>>> dp;
  
    int recFind(int i,int j,int flag,string &s,int n){
        if(i==j){
            if(s[i]=='T'){
                return flag;
            }
            else{
                return !flag;
            }
        }
        if(dp[i][j][flag]!=-1) return dp[i][j][flag];
        int ans = 0;
        for(int idx = i; idx<=j-2; idx+=2){
            int lt = recFind(i,idx,1,s,n);
            int lf = recFind(i,idx,0,s,n);
            int rt = recFind(idx+2,j,1,s,n);
            int rf = recFind(idx+2,j,0,s,n);
            if(s[idx+1]=='|'){
                ans += flag?lt*rt+lt*rf+lf*rt:lf*rf;
            }
            else if(s[idx+1]=='&'){
                ans += flag?lt*rt:lf*rf+lt*rf+lf*rt;
            }
            else{
                ans += flag?lt*rf+lf*rt:lf*rf+lt*rt;
            }
        }
        return dp[i][j][flag]=ans;
    }
  
    int countWays(string &s) {
        // code here
        int n = s.size();
        dp.resize(n,vector<vector<int>> (n,vector<int> (2,-1)));
        return recFind(0,n-1,1,s,n);
    }
};