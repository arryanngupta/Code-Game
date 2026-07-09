class Solution {
  public:
  
    vector<vector<int>> dp;
  
    int recFind(int idx,int sum,vector<int>& arr,int n){
        if(idx==n) return (sum==0);
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        int take = 0,notTake = 0;
        if(sum>=arr[idx]){
            take = recFind(idx+1,sum-arr[idx],arr,n);
        }
        notTake = recFind(idx+1,sum,arr,n);
        return dp[idx][sum]=(take+notTake);
    }
  
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        int n = arr.size();
        
        int s = 0;
        for(auto it: arr) s+=it;
        dp.resize(n,vector<int> (s+1,-1));
        if(s-diff<0 || (s-diff)%2!=0) return 0;
        return recFind(0,(s-diff)/2,arr,n);
    }
};