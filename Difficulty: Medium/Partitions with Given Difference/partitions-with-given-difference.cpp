class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int idx,int s1,int s,vector<int>& arr, int diff,int n){
        if(idx==n){
            // return (s-2*s1==diff);
            return s1==diff;
        }
        if(dp[idx][s1]!=-1) return dp[idx][s1];
        int take = recFind(idx+1,s1+arr[idx],s,arr,diff,n);
        int notTake = recFind(idx+1,s1,s,arr,diff,n);
        return dp[idx][s1]=(take+notTake);
    }
    
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        int s = 0;
        for(auto it: arr) s+= it;
        dp.resize(n,vector<int> (s+1,-1));
        int target = (s+diff);
        if(target%2!=0) return 0;
        return recFind(0,0,s,arr,(s+diff)/2,n);
    }
};


// s1+s2 = s
// s1-s2 = diff
// s1 = (s+diff)/2