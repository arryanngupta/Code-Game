class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int i,int j,string &s1, string &s2,int n,int m){
        if(i==n || j==m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take = 0,notTake = 0;
        if(s1[i]==s2[j]){
            take = 1+recFind(i+1,j+1,s1,s2,n,m);
        }
        notTake = recFind(i+1,j,s1,s2,n,m);
        notTake = max(notTake,recFind(i,j+1,s1,s2,n,m));
        return dp[i][j]=max(take,notTake);
    }
    
    map<pair<int,int>,set<string>> mpp;
  
    set<string> recFind2(int i,int j,string &s1, string &s2){
        if(i==s1.size() || j==s2.size()){
            return {""};
        }
        if(mpp.find({i,j})!=mpp.end()) return mpp[{i,j}];
        set<string> st;
        if(s1[i]==s2[j]){
            auto it = recFind2(i+1,j+1,s1,s2);
            for(auto it1: it) st.insert(s1[i]+it1);
        }
        else{
            if(dp[i+1][j]==dp[i][j+1]){
                st.merge(recFind2(i+1,j,s1,s2));
                st.merge(recFind2(i,j+1,s1,s2));
            }
            else if(dp[i+1][j]>dp[i][j+1]){
                st.merge(recFind2(i+1,j,s1,s2));
            }
            else if(dp[i][j+1]>dp[i+1][j]){
                st.merge(recFind2(i,j+1,s1,s2));
            }
        }
        return mpp[{i,j}]=st;
    }
  
    vector<string> allLCS(string &s1, string &s2) {
        // code here
        int n = s1.size(),m = s2.size();
        dp.resize(n+1,vector<int> (m+1,-1));
        int lcs = recFind(0,0,s1,s2,n,m);
        auto it = recFind2(0,0,s1,s2);
        vector<string> ans;
        for(auto it1: it) ans.push_back(it1);
        return ans;
    }
};
